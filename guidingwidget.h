#ifndef GUIDINGWIDGET_H
#define GUIDINGWIDGET_H

#include <QWidget>

namespace Ui {
class GuidingWidget;
}

class GuidingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GuidingWidget(QWidget *parent = nullptr);
    ~GuidingWidget();

private:
    Ui::GuidingWidget *ui;
};

#endif // GUIDINGWIDGET_H
