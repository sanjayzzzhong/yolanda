
cmake_minimum_required(VERSION 2.8)

project(7_local_socket)

add_executable(unixstreamclient unixstreamclient.c)
add_executable(unixstreamserver unixstreamserver.c)

add_executable(unixdataclient unixdataclient.c)
add_executable(unixdataserver unixdataserver.c)