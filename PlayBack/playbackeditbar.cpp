#include "playbackeditbar.h"
#include "ui_playbackeditbar.h"

PlayBackEditBar::PlayBackEditBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayBackEditBar)
{
    ui->setupUi(this);
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &PlayBackEditBar::canceled);
}

PlayBackEditBar::~PlayBackEditBar()
{
    delete ui;
}
