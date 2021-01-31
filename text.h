#ifndef TEXT_H
#define TEXT_H

#include <QByteArray>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVector>
#include <QWidget>

class Text  : public QObject
{
    Q_OBJECT

private:
    QString description_;
    int pos_;

    unsigned short capacity_;   // Capacity of the text field
    unsigned short size_;       // Actual size of the text field inclusive of the \0 (i.e. capacity_ + 1)

    static QByteArray *data_;

    void detectSize();

public:
    QLineEdit *edit_;
    QLabel *label_;

    Text(int pos, QString description, unsigned short capacity = 0);
    Text() {}
    ~Text() {}

    QString getDesc() { return description_; }
    QString getDescAndLength() { return description_ + " (" + QString::number(capacity_) + ")"; }
    unsigned short getCapacity() { return capacity_; }
    unsigned short getSize() { return size_; }
    QString getText();
    QLabel *getLabel()  { return label_; }
    QLineEdit *getTextBox() { return edit_; }

    static void init(QByteArray &data);
    static void initForm(QFormLayout *form, QVector<Text*> vect);

private slots:
    void setText(QString text);
};

#endif // TEXT_H
