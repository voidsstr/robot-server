#include <iostream>

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

using namespace std;

int main()
{
    boost::asio::io_service io_service;

    try
    {
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

        for(;;)
        {
            tcp::socket socket(io_service);

            acceptor.accept(socket);

            std::string message = "test";

            boost::system::error_code ignored_error;

            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
