//
// Created by Władysław Nowak on 08/04/2021.
//

#ifndef SDIZO1_RBNODE_H
#define SDIZO1_RBNODE_H

enum Color {RED, BLACK};

class RBNode {
private:
    Color color = RED;
    RBNode* right = nullptr;
    RBNode* left = nullptr;
    RBNode* parent = nullptr;
    int data;
public:
    RBNode(int data, Color color):data(data),color(color){};
    explicit RBNode(int data):data(data){};
    /**
     * Get color of this node.
     * @return Enum representing color: RED or BLACK.
     */
    Color getColor() const;

    /**
     * Set the color of this node.
     * @param color Enum Color representing the color to be set: RED or BLACK.
     */
    void setColor(Color color);

    /**
     * Get right son of this node.
     * @return Node representing right son.
     */
    RBNode *getRight() const;

    /**
     * Set right son of this node.
     * @param right Node to be set as this node's right son.
     */
    void setRight(RBNode *right);

    /**
     * Get left son of this node.
     * @return Node representing left son.
     */
    RBNode *getLeft() const;

    /**
     * Set left son of this node.
     * @param left Node to be set as this node's left son.
     */
    void setLeft(RBNode *left);

    /**
     * Get this node's parent.
     * @return Node representing parent of this node.
     */
    RBNode *getParent() const;

    /**
     * Set parent of this node.
     * @param parent Node representing new parent.
     */
    void setParent(RBNode *parent);

    /**
     * Get data that this node is carrying.
     * @return Int value.
     */
    int getData() const;

    /**
     * Set value of this node.
     * @param data Ine value.
     */
    void setData(int data);
};


#endif //SDIZO1_RBNODE_H
