//Original problem: https://leetcode.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <vector>
#include <limits>
#include "mylinkedlist_int.h"

using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists) {
	//edge case: lists is empty
	if (lists.empty())
		return nullptr;

	while (lists.size() > 1) {
		lists.push_back(mergeTwoListsFast(lists[0], lists[1]));
		lists.erase(lists.begin());
		lists.erase(lists.begin());
	}
	return lists.front();
}

ListNode* mergeTwoListsFast(ListNode* list1, ListNode* list2) {
	ListNode* newhead = nullptr;
	ListNode* walker1 = list1;	//head of list 1
	ListNode* walker2 = list2;	//head of list 2

	//initialize newhead with the first/lowest value from either list1 or list2
	//if one list is empty, return the other list
	//if both lists are empty, return nullptr
	if (walker1 != nullptr)
	{
		if (walker2 != nullptr)
		{	//both lists are not empty
			if (walker1->val <= walker2->val)
			{
				newhead = new ListNode(walker1->val);
				walker1 = walker1->next;
			}
			else
			{
				newhead = new ListNode(walker2->val);
				walker2 = walker2->next;
			}
		}
		else
		{	//list2 is empty
			newhead = new ListNode(walker1->val);
			walker1 = walker1->next;
		}
	}
	else if (walker2 != nullptr)
	{	//list1 is empty
		newhead = new ListNode(walker2->val);
		walker2 = walker2->next;
	}
	else
		return newhead;

	ListNode* new_walker = newhead;

	//go through both lists with two parallel pointers, adding the higher value until the ends of both lists have been reached
	while (true)
	{
		if (walker1 != nullptr)
		{
			if (walker2 != nullptr)
			{	//both lists still have stuff in them
				if (walker1->val <= walker2->val)
				{
					//add value from list1 to new list and go further in list1
					new_walker->next = new ListNode(walker1->val);
					walker1 = walker1->next;
				}
				else
				{
					//add value from list2 to new list and go further in list2
					new_walker->next = new ListNode(walker2->val);
					walker2 = walker2->next;
				}

				//move to the end of the new list
				new_walker = new_walker->next;
			}
			else
			{	//at end of list2
				//add value from list1 to new list and go further in list1
				new_walker->next = new ListNode(walker1->val);
				walker1 = walker1->next;

				//move to the end of the new list
				new_walker = new_walker->next;
			}
		}
		else if (walker2 != nullptr)
		{	//at end of list1
			//add value from list2 to new list and go further in list2
			new_walker->next = new ListNode(walker2->val);
			walker2 = walker2->next;

			//move to the end of the new list
			new_walker = new_walker->next;
		}
		else
			return newhead;
	}
}
