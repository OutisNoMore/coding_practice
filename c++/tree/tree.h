#ifndef TREE_H_
#define TREE_H_

class Tree{
	private:
		int _value = 0;
		Tree* _childA = nullptr;
		Tree* _childB = nullptr;

	public:
		Tree(int);
		void recurDelete(Tree*);
		Tree* getA() const;
		Tree* getB() const;
		int getValue() const;
		bool addChild(int);
		bool search(int value) const;
};

#endif // TREE_H_
