/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1022 Digital Library
*  Date: 2021/03/14 TimeOut 2021/03/18 AC
***********************************************/
/***********************************************
* Core Mission:
* Point: use reference of parameter in Query() or it will be time out
***********************************************/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
using namespace std;

typedef map<string, set<string>> QueryTable;

void UpdateTitleQueryTable(string id, string title, QueryTable& title2id) {
	QueryTable::iterator it = title2id.find(title);
	if (it == title2id.end()) {
		set<string> t;
		t.insert(id);
		title2id[title] = t;
	}
	else {
		((*it).second).insert(id);
	}
	return;
}
void UpdateAuthorQueryTable(string id, string author, QueryTable& author2id) {
	QueryTable::iterator it = author2id.find(author);
	if (it == author2id.end()) {
		set<string> t;
		t.insert(id);
		author2id[author] = t;
	}
	else {
		((*it).second).insert(id);
	}
	return;
}
void UpdateKeyWordQueryTable(string id, string all_key_words, QueryTable& key_word2id) {
	stringstream ss(all_key_words);
	string key_word;
	while (ss >> key_word) {
		QueryTable::iterator it = key_word2id.find(key_word);
		if (it == key_word2id.end()) {
			set<string> t;
			t.insert(id);
			key_word2id[key_word] = t;
		}
		else {
			((*it).second).insert(id);
		}
	}
	return;
}
void UpdatePublisherQueryTable(string id, string publisher, QueryTable& publisher2id) {
	QueryTable::iterator it = publisher2id.find(publisher);
	if (it == publisher2id.end()) {
		set<string> t;
		t.insert(id);
		publisher2id[publisher] = t;
	}
	else {
		((*it).second).insert(id);
	}
	return;
}
void UpdateYearQueryTable(string id, string year, QueryTable& year2id) {
	QueryTable::iterator it = year2id.find(year);
	if (it == year2id.end()) {
		set<string> t;
		t.insert(id);
		year2id[year] = t;
	}
	else {
		((*it).second).insert(id);
	}
	return;
}

void Query(QueryTable &query_table, string &query_object) {
	QueryTable::iterator it = query_table.find(query_object);
	if (it == query_table.end()) {
		cout << "Not Found\n";
	}
	else {
		for (auto item : (*it).second) {
			cout << item << endl;
		}
	}
	return;
}

int main(void) {
	QueryTable title2id;
	QueryTable author2id;
	QueryTable key_word2id;
	QueryTable publisher2id;
	QueryTable year2id;
	int books_num; cin >> books_num; 
	for (int i = 0; i < books_num; i++)
	{
		string id;
		string title;
		string author;
		string key_words;
		string publisher;
		string year;
		cin >> id; getchar();
		getline(cin, title);
		getline(cin, author);
		getline(cin, key_words);
		getline(cin, publisher);
		cin >> year;
		UpdateTitleQueryTable(id, title, title2id);
		UpdateAuthorQueryTable(id, author, author2id);
		UpdateKeyWordQueryTable(id, key_words, key_word2id);
		UpdatePublisherQueryTable(id, publisher, publisher2id);
		UpdateYearQueryTable(id, year, year2id);
	}
	int query_num; cin >> query_num; getchar();
	for (int i = 0; i < query_num; i++)
	{
		string ini_query; getline(cin, ini_query);
		int query_type = stoi(ini_query.substr(0, 1));
		string query_object = ini_query.substr(3);
		cout << ini_query << endl;
		switch (query_type) {
		case 1: {
			Query(title2id, query_object);
			break;
		}
		case 2: {
			Query(author2id, query_object);
			break;
		}
		case 3: {
			Query(key_word2id, query_object);
			break;
		}
		case 4: {
			Query(publisher2id, query_object);
			break;
		}
		case 5: {
			Query(year2id, query_object);
			break;
		}
		}
	}

	return 0;
}