Qt TableModel Implementation
============================

This repository is for my tutorial on how Model/View programming works in qt. It shows how to create a TableModel that is based around organizing data in rows.

The code in this branch only allows the default editing provited by QTableView, I have also provided two different implementations:
one where the [delegate creates the editor](https://github.com/Diusrex/Qt-Model-View-Editing-Tutorial/tree/DelegateCreatesEditor), and one where [QItemEditorFactory changes the editor created](https://github.com/Diusrex/Qt-Model-View-Editing-Tutorial/tree/DelegateImplementation).

Requirements to Run
============================

A working installation of Qt 5.

c++11 (or could remove the unique_ptr and replace it with a normal pointer).
