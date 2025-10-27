#include "video_to_mp3_music.h"

#include <QApplication>
#include <QMessageBox>
#include <QSharedMemory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSharedMemory shareMem("Video_to_MP3_music");

    if(shareMem.attach())
    {
        QMessageBox::information(nullptr , "music","Music已经在运行");
        return 0 ;
    }

    shareMem.create(1);

    Video_to_MP3_music w;
    w.show();
    return a.exec();
}

