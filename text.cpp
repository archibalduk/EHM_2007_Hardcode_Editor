#include "text.h"

QByteArray *Text::data_ = nullptr;


/* =========================== */
/*      Class Constructor      */
/* =========================== */

// Default constructor
Text::Text(int pos, QString description, unsigned short capacity) :
    pos_(pos),
    description_(description),
    capacity_(capacity),
    size_(capacity + 1)
{
    if(capacity <= 0)
        detectSize();

    label_ = new QLabel(getDescAndLength() + ":");

    // Initialise the text box and connect the signal and slot to update the data
    edit_ = new QLineEdit(getText());
    edit_->setMaxLength(capacity_);

    QObject::connect(edit_, SIGNAL(textEdited(QString)), this, SLOT(setText(QString)));
}

// Detect text size and capacity
void Text::detectSize()
{
    int pos = pos_;

    // Iterate through each byte until a \0 is reached
    for(; pos < data_->size(); ++pos, ++size_) {
        if(data_->at(pos) == 0)
            break;
    }

    // Iterate through \0 until a non-blank byte is reached (i.e. the end of the text field)
    for(; pos < data_->size(); ++pos, ++size_) {
        if(data_->at(pos) != 0) {
            --size_;    // Reduce size_ by 1 so as to compensate for the loop adding 1 count too many
            break;
        }
    }

    capacity_ = size_ - 1;
}

/* ============================= */
/*      Data Initialisation      */
/* ============================= */

// Assign static pointer to the exe data
void Text::init(QByteArray &data)
{
    data_ = &data;
}

// Populate a form with labels and line entries from a Text* vector
void Text::initForm(QFormLayout *form, QVector<Text*> vect)
{
    for(int i = 0; i < vect.size(); ++i)
        form->addRow(vect[i]->getLabel(), vect[i]->getTextBox());
}

/* ================== */
/*      Get Data      */
/* ================== */

// Get data as a string
QString Text::getText()
{
    return QString(data_->mid(pos_, capacity_));
}


/* ================== */
/*      Set Data      */
/* ================== */

// Set data using a string
void Text::setText(QString text)
{
    // Temporary array. This must be resized and filled before adding the text (and then further resized to avoid truncation).
    QByteArray tmp;
    tmp.resize(capacity_);
    tmp.fill('\0');
    tmp = QByteArray::QByteArray(text.toLatin1());
    tmp.resize(capacity_);

    data_->replace(pos_, capacity_, tmp);
}
