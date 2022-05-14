#include "stringreplacestrategy.h"

// abstract class
StringReplaceStrategy::StringReplaceStrategy()
{
}


// 'first' strategy
StringReplaceFirstStrategy::StringReplaceFirstStrategy()
{
}

QString StringReplaceFirstStrategy::replace(
    const QString& search, const QString& subject, const QString& replace) const
{
    QString result = search;

    int pos = search.indexOf(subject);
    result.replace(pos, subject.size(), replace);

    return result;
}


// 'last' strategy
StringReplaceLastStrategy::StringReplaceLastStrategy()
{
}

QString StringReplaceLastStrategy::replace(
    const QString& search, const QString& subject, const QString& replace) const
{
    QString result = search;

    int pos = search.lastIndexOf(subject);
    result.replace(pos, subject.size(), replace);

    return result;
}


// 'all' strategy
StringReplaceAllStrategy::StringReplaceAllStrategy()
{
}

QString StringReplaceAllStrategy::replace(
    const QString& search, const QString& subject, const QString& replace) const
{
    QString result = search;

    result.replace(subject, replace);

    return result;
}