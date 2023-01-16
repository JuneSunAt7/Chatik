HEADERS       = chatdialog.h \
                client.h \
<<<<<<< HEAD
                connection.h \
                peermanager.h \
                server.h
SOURCES       = chatdialog.cpp \
                client.cpp \
=======
                clientsendfile.h \
                connection.h \
                peermanager.h \
                server.h \
                serversendfile.h \
                socketthread.h
SOURCES       = chatdialog.cpp \
                client.cpp \
                clientsendfile.cpp \
>>>>>>> 818b409 (NEW FILE UPDATE)
                connection.cpp \
                features_ver2.cpp \
                main.cpp \
                peermanager.cpp \
<<<<<<< HEAD
                server.cpp
=======
                server.cpp \
                serversendfile.cpp \
                socketthread.cpp
>>>>>>> 818b409 (NEW FILE UPDATE)
FORMS         = chatdialog.ui
QT           += network widgets
requires(qtConfig(udpsocket))
requires(qtConfig(listwidget))

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/network-chat
INSTALLS += target


