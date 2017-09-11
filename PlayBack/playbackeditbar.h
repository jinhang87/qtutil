#ifndef PLAYBACKEDITBAR_H
#define PLAYBACKEDITBAR_H

#include <QWidget>

namespace Ui {
class PlayBackEditBar;
}

class PlayBackEditBar : public QWidget
{
    Q_OBJECT

public:
    explicit PlayBackEditBar(QWidget *parent = 0);
    ~PlayBackEditBar();

signals:
    void canceled();


private:
    Ui::PlayBackEditBar *ui;
};

#endif // PLAYBACKEDITBAR_H
