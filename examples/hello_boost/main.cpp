#include <iostream>

#include <boost/log/trivial.hpp>
#include <boost/thread/thread.hpp>

void thread_test()
{
    std::cout << "Hello from boost::thread" << std::endl;
}

int main(int argc, char *argv[])
{
    static_cast<void>(argc);
    static_cast<void>(argv);

    std::cout << "Hello Boost" << std::endl;

    boost::thread t1(&thread_test);
    t1.join();

    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
}
