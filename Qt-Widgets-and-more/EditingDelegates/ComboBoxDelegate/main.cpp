/* MIT License

Copyright (C) 2020-2022 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "ComboBoxDelegate.h"
#include "Model.h"
#include <CompanyDelegate.h>
#include <QApplication>
#include <QShortcut>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView view;

    auto delegate1 =
        new ComboBoxDelegate(QStringList{"Sweden", "Germany", "UK", "USA", "France"}, &view);
    delegate1->setEditable(true);
    view.setItemDelegateForColumn(0, delegate1);

    auto factory = [] { return QStringList{"Sweden", "Germany", "UK", "USA", "France"}; };
    auto delegate2 = new ComboBoxDelegate(factory, &view);
    view.setItemDelegateForColumn(1, delegate2);

    view.setItemDelegateForColumn(2, new CompanyDelegate(&view));
    Model model;
    view.setModel(&model);

    view.resize(800, 400);
    view.show();

    auto shortcut = new QShortcut(Qt::CTRL | Qt::Key_Q, &view);
    shortcut->setContext(Qt::ApplicationShortcut);
    QObject::connect(shortcut, &QShortcut::activated, qApp, QCoreApplication::quit);

    return a.exec();
}
