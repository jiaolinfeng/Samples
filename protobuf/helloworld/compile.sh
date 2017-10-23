#!/bin/bash


g++ -o reader reader.c test.helloworld.pb.cc -lprotobuf
g++ -o writer writer.c test.helloworld.pb.cc -lprotobuf
