#ifndef RECTIFYMAPWIDGET_H
#define RECTIFYMAPWIDGET_H

#include <QWidget>
#include <string>
using namespace std;

namespace Ui {
class RectifyMapWidget;
}

class RectifyMapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RectifyMapWidget(QWidget *parent = nullptr);
    ~RectifyMapWidget();

private:
    Ui::RectifyMapWidget *ui;
};

#endif // RECTIFYMAPWIDGET_H
