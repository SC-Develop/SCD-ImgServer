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
### Download project

``` git clone https://github.com/sc-develop/scd-imgserver```

### Build and Run the SCD Image Server

Run QT Creator and load project found into server 'source' subdir, build project and run.<br>
Executable <b>scdimgserver</b>will be generated under the <b>bin</b> folder
At first execution <b>config.cfg</b> file wil be created.<br><br>
To edit <b>config.cfg</b> you can type:

$cd bin<br>
$nano cnfig.cfg
```
[General]
port=12345
rootpath=./
```
Set server port, and image server root path, and save

All images folder tree, will be created ubnde this root path.

Now you can kill and restart server to realod new settings.

You can start server from cli

```
~/bin$ ./scdimssrver
```
You should see somthing like as:
```
SC-Develop Image Server v1.0
Copyright (c) 2019 (MIT) Ing. Salvatore Cerami - dev.salvatore.cerami@gmail.com
https://github.com/sc-develop - git.sc.develop@gmail.com

"Image Server is listening on port:12345 for incoming connections..."

```
## How to compile and run SCD Image Client application utility

### Build and Run the SCD Image Client Applciation

Run QT Creator, load project found into client 'source' subdir and build.
Executable <b>scdimgclient</b>will be genereted under the <b>bin</b> folder

There are five distinct syntax you can use to upload, download and delete file with scdimgclient application.

```
$

## How to embed SCD Image Client Qt C++ Class into yuor own application
