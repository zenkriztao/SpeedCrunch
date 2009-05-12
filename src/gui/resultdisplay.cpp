// This file is part of the SpeedCrunch project
// Copyright (C) 2009 Helder Correia <helder.pereira.correia@gmail.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; see the file COPYING.  If not, write to
// the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
// Boston, MA 02110-1301, USA.

#include "3rdparty/flickcharm/flickcharm.h"
#include "gui/resultdisplay.hxx"

#include "core/functions.hxx"
#include "core/settings.hxx"
#include "gui/syntaxhighlighter.hxx"
#include "math/hmath.hxx"
#include "math/floatconfig.h"

#include <QtCore/QTimer>
#include <QtGui/QApplication>
#include <QtGui/QClipboard>
#include <QtGui/QScrollBar>

struct ResultDisplay::Private
{
  QStringList contents;
  int         count;
  bool        customAppearance;
  QColor      customBackgroundColor;
  QColor      customBackgroundAlternateColor;
  QColor      customTextColor;
  //FlickCharm  flickCharm;
  SyntaxHighlighter * highlighter;
};

ResultDisplay::ResultDisplay( QWidget * parent, const char * name )
    : QPlainTextEdit( parent ), d( new ResultDisplay::Private )
{
    d->customAppearance = false;
    d->count = 0;
    d->customTextColor = QColor( 255, 255, 255 );
    d->customBackgroundColor = QColor( 0, 0, 0 );
    d->customBackgroundAlternateColor = QColor( 21,  21,  21 );
    d->highlighter = new SyntaxHighlighter( this );
    d->highlighter->rehighlight();
    //d->flickCharm.activateOn( this );

    setBackgroundRole( QPalette::Base );
    setLayoutDirection( Qt::LeftToRight );
    setMinimumWidth( 150 );
    setObjectName( name );
    setReadOnly( true );
    setTabChangesFocus( true );
    setWordWrapMode( QTextOption::WrapAnywhere );
}

QString ResultDisplay::asText() const
{
    return toPlainText();
}

void ResultDisplay::append( const QString & expr, const HNumber & value )
{
    ++d->count;

    appendPlainText( expr );
    appendPlainText( QLatin1String("    =  ") + formatNumber(value) );
    appendPlainText( QLatin1String("") );
    ensureCursorVisible();

    // REFACTOR: this only serves to save a session, nonsense
    d->contents.append( expr );
    const char format = value.format() != 0 ? value.format() : 'e';
    char * str = HMath::format( value, format, DECPRECISION );
    d->contents.append( str );
    free( str );
}

void ResultDisplay::appendHistory( const QStringList & history, const QStringList & results )
{
    const int count = history.count();
    for ( int i = 0 ; i < count; ++i )
    {
        QByteArray a = results.at(i).toLatin1();
        HNumber result( a.constData() );

        if      ( a.indexOf('b') == 1 ) result.setFormat( 'b' );
        else if ( a.indexOf('o') == 1 ) result.setFormat( 'o' );
        else if ( a.indexOf('x') == 1 ) result.setFormat( 'h' );

        if ( results.at(i) == "NaN" || ! result.isNan() )
            append( history.at(i), result );
    }
}

int ResultDisplay::count() const
{
    return d->count;
}

bool ResultDisplay::customAppearance() const
{
    return d->customAppearance;
}

QColor ResultDisplay::customBackgroundColor() const
{
    return d->customBackgroundColor;
}

QColor ResultDisplay::customBackgroundAlternateColor() const
{
    return d->customBackgroundAlternateColor;
}

QColor ResultDisplay::customTextColor() const
{
    return d->customTextColor;
}

QString ResultDisplay::formatNumber( const HNumber & value )
{
    Settings * settings = Settings::instance();
    const char format = value.format() != 0 ? value.format() : settings->resultFormat;
    char * str = HMath::format( value, format, settings->resultPrecision );
    QString s = QString::fromLatin1( str );
    free( str );
    if ( settings->radixCharacter() != '.' )
        s.replace( '.', settings->radixCharacter() );
    return s;
}

void ResultDisplay::setCustomAppearance( bool custom )
{
    d->customAppearance = custom;
    QColor bgcolor = QApplication::palette().base().color();
    if ( custom )
        bgcolor = customBackgroundColor();

    QPalette pal = palette();
    pal.setColor( QPalette::Background, bgcolor );
    setPalette( pal );

    refresh();
}

void ResultDisplay::setCustomBackgroundColor( const QColor & base, const QColor & alternate )
{
    d->customBackgroundColor = base;
    d->customBackgroundAlternateColor = alternate;
    if ( d->customAppearance ) {
        QPalette pal = palette();
        pal.setColor( QPalette::Base, base );
        setPalette( pal );
    }
    refresh();
}

void ResultDisplay::setCustomTextColor( const QColor & c )
{
    d->customTextColor = c;
    refresh();
}

ResultDisplay::~ResultDisplay()
{
}

void ResultDisplay::clear()
{
    d->count = 0;
    d->contents.clear();
    setPlainText( QLatin1String("") );
}

void ResultDisplay::scrollEnd()
{
}

void ResultDisplay::handleResultFormatChange()
{
    // refresh();
}

void ResultDisplay::handleResultPrecisionChange()
{
    // refresh();
}

void ResultDisplay::handleRadixCharacterChange()
{
    // refresh();
}

void ResultDisplay::refresh()
{
}

