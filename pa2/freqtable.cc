#include "freqtable.h"
#include <iostream>
#include <string.h>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

// do not change any of the public methods
// they should remain intact, so the autograder can grade your work

// Q1 -- 5 pts
// constructor of the tree
FreqTable::FreqTable(){
	root = NULL;
	n_elem = 0;
}

// Q2 -- 5 pts
// destructor of the tree
FreqTable::~FreqTable(){
	destroy(root);
}

void FreqTable::destroy(BSTNode *p) {
    if (p) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

void FreqTable::insert(const char *str){
	insert(&root, str);
}

// Q3 -- 20 pts
// if the word already exists in the tree, just update the counter
// otherwise make an insertion of a new word
void FreqTable::insert(BSTNode **p, const char *str){
	string data = string(str);
	transform(data.begin(), data.end(), data.begin(), ::tolower);
	const char *cstr = data.c_str();
	if(! *p){
		//if the node is null, can insert here and increment n_elem
        (*p) = new BSTNode(cstr);
        n_elem++;
    }else{
    	//if the word is already in the tree, just increment it's count
    	if((*p)->word == cstr) (*p)->count++;
    	//find the spot where the word should go alphabetically
    	else if((*p)->word > cstr) insert(&((*p)->left), cstr);
    	else if((*p)->word < cstr) insert(&((*p)->right), cstr);
    }
}

// Q4 -- 10 pts
// returns true if the word exists in the tree
// false otherwise
bool FreqTable::contains(const char *str){
	contains(root, str);
}

bool FreqTable::contains(BSTNode *p, const char *str){
	//make str lowercase
	string data = string(str);
	transform(data.begin(), data.end(), data.begin(), ::tolower);
	const char *cstr = data.c_str();
	/*if the node is empty, return false, this only happens if the 
	node is empty, then we've come to the end of the search, bottom 
	of the tree where it's should be if it were in the tree*/
	if(p){
		/*if word at the node we're looking at is the same
		 as what we're looking for, return true*/
		if(p->word == cstr) return true;
		
		/*otherwise, check if the word is alphabetically before
		the word at the node we're looking at, if so go down the
		left branch and keep looking*/
		else if(p->word > cstr) return contains(p->left, cstr);
		else return contains(p->right, cstr);
	}
	return false;
}

BSTNode* FreqTable::leftmost(BSTNode *p){
    BSTNode *most;
    /*keep going down the tree until you reach a node without 
    a left node, that one will be returned*/
    if (p->left == NULL)
        most = p;
    else
        most = leftmost(p->left);

    return most;
}

// Q5 -- 20 pts
// if there is more than one occurrence of the word in the tree
// decrease the counter, otherwise delete the node
void FreqTable::erase(const char *str){
	erase(root, str);
}

BSTNode* FreqTable::erase(BSTNode *p, const char *str){
	//make str lowercase
	string data = string(str);
	transform(data.begin(), data.end(), data.begin(), ::tolower);
	const char *cstr = data.c_str();
	//can't erase root node for some reason?? whyyyy
	if(!empty(p)){
		/*if node's word is what we're trying to erase and it
		has a frequency of more than 1, just reduce it's count 
		by one*/
		if(p->word == cstr && p->count > 1){
			p->count--;
			return p;
		//}else if(p->word== cstr && p == root){

		//if the node only has a count of one and we've found it
		}else if(p->word == cstr){
			/*if both child nodes of the node to delete are empty,
			reduce number of elements count by 1, 
			and return null so its parent is updated to null*/
			if(empty(p->left) && empty(p->right)){
				n_elem--;
				return NULL;
			/*if the node has 2 child nodes (the most complex 
				situation), make current node equal the leftmost node
				on the right branch of whatever node you're looking
				at (that node is the closest to value of the node
				we're looking at). Then erase the leftmost node because
				it's now a duplicate (it won't have a left child
				node so it's erasure is easier).  n_elem will get
				changed when the duplicate is deleted.*/
			}else if(!empty(p->left) && !empty(p->right)){
				BSTNode *temp = p;
				p = leftmost(p->right);
				p->left = temp->left;
				p->right = temp->right;
				erase(p->right, p->word.c_str());
			}
			/*if the node to erase has only one node on the right,
				reduce n_elem to keep it up to date with what's about
				to happen, and just return the right, not empty node
				because that one will take it's place.*/
			else if(!empty(p->right) && empty(p->left)){
				n_elem--;
				p = p->right;
				return p->right;
			}
			/*same as above but in the case of the left branch
			being the only child of the node to erase.*/
			else if(!empty(p->left) && empty(p->right)){
				n_elem--;
				p = p->left;
				return p->left;
			}
			else return NULL;
		}
		/*if the word to erase isn't at this node, move
		over according to where it is alphabetically in 
		relation to the current node's word
		set the right node to what it is or if it's changing
		right (or left) gets updated to what it will be
		(can be changed to null)*/
		else if(cstr > p->word)
			p->right = erase(p->right, cstr);
		else if(cstr < p->word)
			p->left = erase(p->left, cstr);
	}
	return p;
}

// Q6 -- 5 pts
// returns true if the tree is empty, false otherwise
bool FreqTable::empty(){
	empty(root);
}

bool FreqTable::empty(BSTNode *p){
	//if node is null, return true
	if(!p){
		return true;
	}else{
		return false;
	}
}

// Q7 -- 5 pts
// returns how many different words are in the tree
unsigned int FreqTable::size(){
	return n_elem;
}

// Q8 -- 15 pts
// remove all words from the tree and sets n_elem to zero
void FreqTable::clear(){
	if(!empty(root)) clear(root);
	root = NULL;
}

void FreqTable::clear(BSTNode *p){
	if(!empty(p->right)) clear(p->right);
	if(!empty(p->left)) clear(p->left);
	if(!empty(p)) delete p;
	n_elem = 0;
}

// Q9 -- 15 pts
// print (to the standard output) the frequency table in lexicographical
// order using this format:
// one word should be printed per line, followed by one whitespace, followed
// by the number of occcurrences of this word in the tree
void FreqTable::print_all(){
	print_all(root);
}

void FreqTable::print_all(BSTNode *p){
	if(!empty(p)){
		print_all(p->left);
		cout<< p->word <<" "<<p->count <<endl;
		print_all(p->right);
	}
}
