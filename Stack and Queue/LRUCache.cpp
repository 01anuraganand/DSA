#include <iostream>
#include <unordered_map>
using namespace std;
class LRUCache
{
public:
	class Node
	{
	public:
		int key;
		int val;
		Node * next;
		Node * prev;
		Node(int _key, int _val)
		{
			key = _key;
			val = _val;
		}
	};
	
	Node * head = new Node(-1, -1);
	Node * tail = new Node(-1, -1);
	
	int cap;
	unordered_map<int ,Node*> m;
	
	LRUCache(int capacity)
	{
		cap = capacity;
		head->next = tail;
		tail->prev = head;
	}
	
	void addNode(Node * newnode)
	{
		Node *temp = head->next;
		newnode->next = temp;
		newnode->prev = head;
		head->next = newnode;
		temp->prev = newnode;
	}
	
	void deleteNode(Node * deletenode)
	{
		Node *deletePrev = deletenode->prev;
		Node *deleteNext = deletenode->next;
		deletePrev->next = deleteNext;
		deleteNext->prev = deletePrev;
	}
	
	int get(int key_)
	{
		if(m.find(key_) != m.end())
		{
			Node * hitNode = m[key_];
			int hit = hitNode->val;
			m.erase(key_);
			deleteNode(hitNode);
			addNode(hitNode);
			m[key_] = head->next;
			return hit;
		}
		return -1;
	}
	
	void put(int key_, int value)
	{
		if(m.find(key_) != m.end())
		{
			Node * existNode = m[key_];
			m.erase(key_);
			deleteNode(existNode);
		}
		if(m.size() == cap)
		{
			m.erase(tail->prev->key);
			deleteNode(tail->prev);
		}
		addNode(new Node(key_, value));
		m[key_] = head->next;
	}
	
};



int main()
{
	int capacity;
	cout<<"Enter the cache capacity:"<<endl;
	cin>>capacity;
	LRUCache *obj = new LRUCache(capacity);
	obj->put(1,1);
	obj->put(2,2);
	cout<<obj->get(1)<<endl;
	obj->put(3,3);
	cout<<obj->get(2)<<endl;
	obj->put(4,4);
	cout<<obj->get(1)<<endl;
	cout<<obj->get(3)<<endl;
	cout<<obj->get(4)<<endl;
	
}