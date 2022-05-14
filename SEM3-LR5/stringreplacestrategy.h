#pragma once

#include <QtCore>

class StringReplaceStrategy
{
public:
    StringReplaceStrategy();

    virtual QString replace(const QString& search, const QString& subject,
        const QString& replace) const = 0;
};

// first  occurrence
class StringReplaceFirstStrategy :
    public StringReplaceStrategy
{
public:
    StringReplaceFirstStrategy();

    QString replace(const QString& search, const QString& subject,
        const QString& replace) const;
};

// last occurrence
class StringReplaceLastStrategy :
    public StringReplaceStrategy
{
public:
    StringReplaceLastStrategy();

    QString replace(const QString& search, const QString& subject,
        const QString& replace) const;
};

// all occurrences
class StringReplaceAllStrategy :
    public StringReplaceStrategy
{
public:
    StringReplaceAllStrategy();

    QString replace(const QString& search, const QString& subject,
        const QString& replace) const;
};

