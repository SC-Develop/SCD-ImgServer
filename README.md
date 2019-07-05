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

Run QT Creator and load project found into server 'source' subdir, build project and run.<br><br>
Binary executable <b>scdimgserver</b> will be generated under the <b>bin</b> folder<br>
At first execution <b>config.cfg</b> file wil be created.<br><br>
To edit <b>config.cfg</b> you can type:

$cd bin<br>
$nano cnfig.cfg
```
[General]
port=12345
rootpath=./
```
Set server port, and image server root path, and save.<br>

All images folder tree, will be created ubnde this root path.<br>

Now you can kill and restart server to realod new settings.<br>

You can start server from cli:

```
~/bin$ ./scdimssrver
```
You should see something like as:

```
SC-Develop Image Server v1.0
Copyright (c) 2019 (MIT) Ing. Salvatore Cerami - dev.salvatore.cerami@gmail.com
https://github.com/sc-develop - git.sc.develop@gmail.com

"Image Server is listening on port:12345 for incoming connections..."
```
## How to compile and run SCD Image Client application utility

### Build and Run the SCD Image Client Applciation

Run QT Creator, load project found into client 'source' subdir and build.<br>
Binary executable <b>scdimgclient</b> will be genereted under the <b>bin</b> folder<br>

There are five distinct syntax you can use to upload, download and delete file with scdimgclient application.

Type
```
~/bin/ ./scdimgclient
```
You should see something like as: 

```
SC-Develop Image Client v1.0
Copyright (c) 2019 (MIT) Ing. Salvatore Cerami - dev.salvatore.cerami@gmail.com
https://github.com/sc-develop - git.sc.develop@gmail.com

Usage scdimgclient <host> <port> <PUT> <file path to transfer> <dest file path>
Usage scdimgclient <host> <port> <PUT> <folder path to transfer> <dest file path> -f 
Usage scdimgclient <host> <port> <GET> <remote file path to get> [-file:<file path>] [-T]
Usage scdimgclient <host> <port> <DEL> <remote file path to delete>
```
## Example of five syntax usage.

### Syntax 1: Upload a photo

```
~/bin$ ./scdimgclient localhost 12345 PUT ./sicily/caltanissetta/1.png /sicily/cl/photo1.png
```
Destination path name <b>must</b> start with <b>'/'</b>, and destination filename <b>must be</b> specified.<br>

The path <b>/sicily/cl/</b> will be appended under the server root path specified into <b>config.cfg</b> file. 

### Syntax 2: Download a photo

```
~/bin$ ./scdimgclient localhost 12345 GET /sicily/cl/photo1.png -file:./download/sicily/cl/
```
Remote file path name <b>must</b> start with <b>'/'</b> and it is relative to the server root path specified into <b>config.cfg</b> file. <br>
Destination filename <b>must not</b> be specified.<br>

The path <b>./download/sicily/cl/</b> will be created on the client file system. 

### Syntax 3: Download a thumbnail

```
~/bin$ ./scdimgclient localhost 12345 GET /sicily/cl/photo1.png -file:./download/sicily/cl/ -T
```
### Syntax 4: Delete a remote file

```
~/bin$ ./scdimgclient localhost 12345 DEL /sicily/cl/photo1.png
```
Remote file path name <b>must</b> start with <b>'/'</b> and it is relative to the server root path specified into <b>config.cfg</b> file. <br>

### Syntax 5: Upload a photo folder

```
~/bin$ ./scdimgclient localhost 12345 PUT ./sicily/caltanissetta/ /sicily/cl/photo1.png
```
Destination path name <b>must</b> start with <b>'/'</b> and it is relative to the server root path specified into <b>config.cfg</b> file. <br>
The path <b>/sicily/cl/</b> will be appended under the server root path specified into <b>config.cfg</b> file. 

## How to embed SCD Image Client Qt C++ Class into yuor own application

You must include on you own Qt Project

- scdimagclient.h
- scdimgclient.cpp

On you main function or into man window constructor:
```
#include "scdimgclient.h"

void main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
      
   .
   .
   .
   
   int Port     = 12345;
   QString host = "localhost";
   
   SCDImgClient imgc(host,Port,10000); // declare the client obj

   // connect your client desidered events...

   imgc.connect(&imgc, &SCDImgClient::notifyConnected,  onConnect);
   imgc.connect(&imgc, &SCDImgClient::notifyDisconnect, onDisconnect);
   imgc.connect(&imgc, &SCDImgClient::notifyError,      onError);
   imgc.connect(&imgc, &SCDImgClient::finished,         onFinished);
   imgc.connect(&imgc, &SCDImgClient::fileReceived,     onFileReceived);
   imgc.connect(&imgc, &SCDImgClient::fileSaving,       onFileSaving);
   
   imgc.start();
   
   .
   .
   .
   a.exec();
}
```
At this point you can implement the code of each slot connected...<br><br>

What are you waiting for? Try it now! It's really simple and fast.<br>

See the scdimgclient code for further explaination!<br>

I wish you a good job.


