#pragma once

#include <QObject>

struct Node
{
    QString	    data;
    Node *		left;
    Node *		right;
};

typedef struct Node Node;

class TreeGraphs : public QObject
{
    Q_OBJECT

public:
    TreeGraphs(QObject *parent = nullptr);
    ~TreeGraphs();

    QString                             TreeConstructor(QStringList strArr);
    QString	                            PreorderTraversal(QStringList strArr);



 protected:
    QVector<QPair<int, int>>	        ParseInput(QVector<QString> input);
    void								ParseInputString(QString str, int & num1, int & num2);

    Node *								FillTree(QVector<QString> input, Node * root, int index, int length);
    Node *								CreateTreeNode(QString data);


    // Preorder Traversal code challenge
    QString							    CreatePreorderOutput(Node * node);


};
