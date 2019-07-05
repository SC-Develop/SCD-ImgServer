# SCD Image Server/Client (Qt/C++)
Fast TCP transfer of large image or file

## Description
The SCD Image Server, is a light and fast TCP Server which allow you to transfer large image (HD/Full HD)
or generic file, without using the standard protocols like HTTP or FTP.
The server use a very simple application level protocol which allow the one shot content trasfer.
Be care, because there are not a bandwidth flow control, and this can fully consume your network bandwidth during transferring.

## Purpose

The purpose of this project is to create a database of images or files of relatively large size residing on the file
server system.
In fact, it is not always a good idea to store large files directly in a database such as inside
blob fields of a MySql database. With this application it is possible to stream files (upload / download) quickly,
keeping the database size contained. While inside the database it is possible to store, for example, a table that indexes the information of the files transferred such as name, file path, size, etc.
Furthermore, the database and files may also reside on different units and / or on different servers, creating an effective
data distribution between traditional database (Mysql for example) and file system.
Also, embedding the SCDImgClient class into your application will be possible to communicate  with the image server for upload/download/delete file, without having to worry about details of client implementation: easy, fast and reliable.

## What you can do with SCD Image Server

SCD Image Server is  also distributed with a simple client application which demonstrate how to use SCD Image Client Class, and his functionalities.

With SCD Image Client you can:

- send (upload) a file to server specifiying where the server must save the received file.
- send (upload) a files folder to server specifiying where the server must save the received files folder
- request to server (download) a specific file, and download it
- request to server (download) a specific file thumbnail, and download it
- request to server to delete a file from server file system

## How to compile and run SCD Image Server
#download project

```git clone https://github.com/sc-develop/scd-imgserver

Run QT Creator and load project found into 'source' subdir. 
Build project and run.
At first execution config.cfg file wil be created.


## How to complie and run SCD Image Client application utility

## How to embed SCD Image Client Qt C++ Class into yuor own application
