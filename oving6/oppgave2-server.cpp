#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace boost::asio::ip;

class HttpServer {
private:
    class Connection {
    public:
        tcp::socket socket;

        Connection(boost::asio::io_context &io_context)
            : socket(io_context) {}
    };

    boost::asio::io_context io_context;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;


    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();

        boost::asio::async_read_until(
            connection->socket,
            *read_buffer,
            "\r\n",
            [connection, read_buffer]
            (const boost::system::error_code &ec, size_t) {

                if (ec)
                    return;

                istream read_stream(read_buffer.get());

                string method;
                string path;
                string version;

                // GET / HTTP/1.1
                read_stream >> method >> path >> version;

                string status;
                string body;

                if (method == "GET" && path == "/") {
                    status = "200 OK";
                    body = "Dette er hovedsiden";
                }
                // For å teste dette: http://localhost:8080/en_side
                else if (method == "GET" && path == "/en_side") {
                    status = "200 OK";
                    body = "Dette er en side";
                }
                else {
                    // For å teste dette: f.eks http://localhost:8080/123
                    status = "404 Not Found";
                    body = "404 Not Found";
                }

                auto response = make_shared<string>(
                    "HTTP/1.1 " + status + "\r\n"
                    "Content-Type: text/plain; charset=utf-8\r\n"
                    "Content-Length: " + to_string(body.size()) + "\r\n"
                    "Connection: close\r\n"
                    "\r\n"
                    + body
                );

                boost::asio::async_write(
                    connection->socket,
                    boost::asio::buffer(*response),
                    [connection, response]
                    (const boost::system::error_code &, size_t) {
                        connection->socket.close();
                    }
                );
            }
        );
    }


    void accept() {
        auto connection = make_shared<Connection>(io_context);

        acceptor.async_accept(
            connection->socket,
            [this, connection]
            (const boost::system::error_code &ec) {

                // Gjør serveren klar for neste klient
                accept();

                if (!ec)
                    handle_request(connection);
            }
        );
    }


public:
    HttpServer()
        : endpoint(tcp::v4(), 8080),
          acceptor(io_context, endpoint) {}


    void start() {
        accept();
        io_context.run();
    }
};


int main() {
    HttpServer server;

    cout << "Server running on http://localhost:8080" << endl;

    server.start();
}