#include "stdafx.h"
#include <stdlib.h>


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
//Classes
class Movie;
class MovieNode;
class MovieList;
class Director;
class DirectorNode;
class DirectorList;
class Actor;
class ActorNode;
class ActorsList;
class MoviesActedIn;
class MoviesDirected;

class Movie {
public:

	DirectorNode* director;
	ActorNode* actor[3];
	string movie_title;
	unsigned long int gross;
	string genre;
	short int title_year;
	float imdb_score;
	short int num_critic_for_reviews;
	short int duration;
	int num_voted_users;
	short int cast_total_facebook_likes;
	short int facenumber_in_poster;
	string plot_keywords;
	string movie_imdb_link;
	unsigned short int num_user_for_reviews;
	string language;
	string country;
	string content_rating;
	unsigned long long int budget;
	unsigned short int aspect_ratio;
	int movie_facebook_likes;
	bool color;//true if colour while false is black and white
};

class MovieNode {
public:
	Movie data;
	MovieNode* next;
};
class Actor {
public:
	string actor_name;
	unsigned short int actor_facebook_likes;
	MoviesActedIn* moviesActedIn;// give only start
};
class ActorNode {
public:
	Actor data;
	ActorNode* next;

};
class MoviesDirected {
public:
	MovieNode* start;
	MovieNode* last;
	MovieNode* ploc;
	MovieNode* loc;

	MoviesDirected() {
		start = NULL;
		ploc = NULL;
		loc = NULL;
		last = NULL;
	}
	bool isEmpty() {
		if (start == NULL)
			return true;
		else
			return false;
	}
	void InsertAtFront(MovieNode* node) {

		if (isEmpty() == true) {
			start = node;
			last = node;
		}
		node->next = NULL;
		start = node;

	}
	void InsertAtEnd(MovieNode* node) {

		if (isEmpty()) {
			start = node;
			last = node;

		}
		last->next = node;
		last = node;
	}

	void insertvalueatmid(MovieNode* node) {

		node->next = ploc->next;
		ploc->next = node;
	}



	void InsertSorted(MovieNode* node) {

		if (loc == NULL && ploc == NULL)
			InsertAtFront(node);

		else
			if (ploc == last) {
				InsertAtEnd(node);
			}
			else if (ploc != NULL && loc == NULL)
				insertvalueatmid(node);
	}

	void Printlist() {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			cout << loc->data.movie_title << endl;
			ploc = loc;
			loc = loc->next;
		}
	}
	bool Search_movie_genre(string g) {
		loc = start;
		ploc = NULL;
		bool found = false;
		while (loc != NULL && found == false) {
			if (loc->data.genre.find(g) != string::npos) {
				found = true;
			}
			ploc = loc;
			loc = loc->next;


		}
		return found;
	}

};

class MoviesActedIn {
public:
	MovieNode* start;
	MovieNode* last;
	MovieNode* ploc;
	MovieNode* loc;

	MoviesActedIn() {
		start = NULL;
		ploc = NULL;
		loc = NULL;
		last = NULL;
	}
	bool isEmpty() {
		if (start == NULL)
			return true;
		else
			return false;
	}
	void InsertAtFront(MovieNode* node) {

		if (isEmpty() == true) {
			start = node;
			last = node;
		}
		node->next = NULL;
		start = node;

	}
	void InsertAtEnd(MovieNode* node) {

		if (isEmpty()) {
			start = node;
			last = node;

		}
		last->next = node;
		last = node;
	}

	void insertvalueatmid(MovieNode* node) {

		node->next = ploc->next;
		ploc->next = node;
	}



	void InsertSorted(MovieNode* node) {

		if (loc == NULL && ploc == NULL)
			InsertAtFront(node);

		else
			if (ploc == last) {
				InsertAtEnd(node);
			}
			else if (ploc != NULL && loc == NULL)
				insertvalueatmid(node);
	}
	bool SearchMovie(MovieNode* m) {
		loc = start;
		ploc = NULL;
		if (loc->data.movie_title == m->data.movie_title) {
			return true;
		}
		ploc = loc;
		loc = loc->next;

	}
	void Printlist() {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			cout << loc->data.movie_title << endl;
			cout << loc->data.title_year << endl;
			ploc = loc;
			loc = loc->next;
		}
	}
	void PrintList_CoActor(string s) {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			cout << loc->data.movie_title << endl;
			for (int i = 0; i <= 2; i++) {
				if (loc->data.actor[i]->data.actor_name == s)
					continue;
				cout << loc->data.actor[i]->data.actor_name << endl;
			}
			ploc = loc;
			loc = loc->next;
		}
	}
	void PrintList_CoActor_of_CoActor(string s) {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			cout << loc->data.movie_title << endl;
			for (int i = 0; i <= 2; i++) {
				if (loc->data.actor[i]->data.actor_name == s)
					continue;
				cout << loc->data.actor[i]->data.actor_name << endl;
				loc->data.actor[i]->data.moviesActedIn->PrintList_CoActor(loc->data.actor[i]->data.actor_name);
			}
			ploc = loc;
			loc = loc->next;
		}
	}
	void CheckCoActor(string coactor2) {
		loc = start;
		ploc = NULL;
		bool found = false;
		while (loc != NULL) {
			for (int i = 0; i <= 2; i++) {
				if (loc->data.actor[i]->data.actor_name == coactor2) {
					found = true;
					cout << "They are co actors" << endl;
					break;
				}
			}
			if (found == true)
				break;
			ploc = loc;
			loc = loc->next;
		}
		if (found != true)
			cout << "They are not co actors" << endl;
	}
	void Print_Unique_CoActors(string s) {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			cout << loc->data.movie_title << endl;
			for (int i = 0; i <= 2; i++) {
				if (s.find(loc->data.actor[i]->data.actor_name) != string::npos) {
					continue;
				}
				else {

					cout << loc->data.actor[i]->data.actor_name << endl;
					s = s + loc->data.actor[i]->data.actor_name;
				}
			}
			ploc = loc;
			loc = loc->next;
		}
	}

};



class Director {
public:
	string director_name;
	unsigned short int director_facebook_likes;
	MoviesDirected* moviesDirected;
};
class DirectorNode {
public:
	Director data;
	DirectorNode* next;
};
class DirectorList {
public:
	DirectorNode* start;
	DirectorNode* last;
	DirectorNode* ploc;
	DirectorNode* loc;

	DirectorList() {
		start = NULL;
		ploc = NULL;
		loc = NULL;
		last = NULL;
	}
	bool isEmpty() {
		if (start == NULL)
			return true;
		else
			return false;
	}
	void InsertAtFront(DirectorNode* node) {

		if (isEmpty() == true) {
			start = node;
			last = node;
		}
		node->next = NULL;
		start = node;

	}
	void InsertAtEnd(DirectorNode* node) {

		if (isEmpty()) {
			start = node;
			last = node;

		}
		last->next = node;
		last = node;
	}

	void insertvalueatmid(DirectorNode* node) {

		node->next = ploc->next;
		ploc->next = node;
	};



	void InsertSorted(DirectorNode* node) {

		if (loc == NULL && ploc == NULL)
			InsertAtFront(node);

		else
			if (ploc == last) {
				InsertAtEnd(node);
			}
			else if (ploc != NULL && loc == NULL)
				insertvalueatmid(node);
	}
	DirectorNode* search(DirectorNode* a) {
		loc = start;
		while (loc != NULL && (loc->data.director_name != a->data.director_name)) {

			ploc = loc;
			loc = loc->next;
		}
		return loc;
	}
	DirectorNode* search(unsigned short int x) {
		loc = start;
		while (loc != NULL && (loc->data.director_facebook_likes != x)) {

			ploc = loc;
			loc = loc->next;
		}
		return loc;
	}
	void Search_Directed_Movie(string s) {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			if (loc->data.director_name == s)
				loc->data.moviesDirected->Printlist();

			ploc = loc;
			loc = loc->next;
		}
	}
	void Search_directors_by_genre(string g) {
		loc = start;
		ploc = NULL;
		cout << "directors who have directed movies of genre " << g << "are :" << endl;
		while (loc != NULL) {
			if (loc->data.moviesDirected->Search_movie_genre(g)) {
				cout << loc->data.director_name << endl;
			}
			ploc = loc;
			loc = loc->next;
		}

	}
	void Printlist() {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			cout << loc->data.director_name << endl;
			ploc = loc;
			loc = loc->next;
		}
	}
	void PrintDirectorWithMovies() {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			cout << loc->data.director_name << endl;
			loc->data.moviesDirected->Printlist();
			ploc = loc;
			loc = loc->next;
		}
	}

};

class ActorsList {
public:
	ActorNode* start;
	ActorNode* last;

	ActorNode* ploc;
	ActorNode* loc;


	ActorsList() {
		start = NULL;
		ploc = NULL;
		loc = NULL;
		last = NULL;
	}
	bool isEmpty() {
		if (start == NULL)
			return true;
		else
			return false;
	}
	void InsertAtFront(ActorNode* node) {

		if (isEmpty() == true) {
			start = node;
			last = node;
		}
		node->next = NULL;
		start = node;
	}
	void InsertAtEnd(ActorNode* node) {

		if (isEmpty()) {
			start = node;
			last = node;

		}
		last->next = node;
		last = node;
	}

	void insertvalueatmid(ActorNode* node) {

		node->next = ploc->next;
		ploc->next = node;
	}



	void InsertSorted(ActorNode* node) {

		if (loc == NULL && ploc == NULL)
			InsertAtFront(node);

		else
			if (ploc == last) {
				InsertAtEnd(node);
			}
			else if (ploc != NULL && loc == NULL)
				insertvalueatmid(node);
	}

	ActorNode* search(ActorNode* a) {
		loc = start;
		while (loc != NULL && (loc->data.actor_name != a->data.actor_name)) {
			ploc = loc;
			loc = loc->next;

		}
		return loc;
	}
	ActorNode* search(string s) {
		loc = start;
		while (loc != NULL && (loc->data.actor_name != s)) {
			ploc = loc;
			loc = loc->next;
		}
		return loc;
	}
	void Profile_Actor(ActorNode* a) {
		ActorNode* temp;
		temp = search(a);
		if (temp == NULL) {
			cout << "not found" << endl;
		}
		else
		{
			cout << "Actor name: " << temp->data.actor_name << endl;
			cout << "Movies and years released" << endl;
			temp->data.moviesActedIn->Printlist();
		}

	}
	void Print_CoActor(string ActorName) {
		ActorNode* temp;
		temp = search(ActorName);
		if (temp == NULL)
			cout << "actor not found" << endl;
		else {
			temp->data.moviesActedIn->PrintList_CoActor(ActorName);
		}
	}

	void Print_CoActor_of_CoActor(string ActorName) {
		ActorNode* temp;
		temp = search(ActorName);
		if (temp == NULL)
			cout << "actor not found" << endl;
		else {
			temp->data.moviesActedIn->PrintList_CoActor_of_CoActor(ActorName);
		}
	}

	void CheckCoActor(string ActorName, string CoActorName) {
		ActorNode* temp;
		temp = search(ActorName);
		if (temp == NULL)
			cout << "Actor not found" << endl;
		else {
			temp->data.moviesActedIn->CheckCoActor(CoActorName);
		}
	}
	void Print_Unique_CoActors(string s) {//function 3

		ActorNode* temp;
		temp = search(s);

		if (temp == NULL)
			cout << "actor not found" << endl;
		else {
			temp->data.moviesActedIn->Print_Unique_CoActors(s);
		}

	}




};
class RatingSortedList {
public:
	MovieNode* start;
	MovieNode* last;

	MovieNode* ploc;
	MovieNode* loc;
	ActorsList* al = new ActorsList();
	DirectorList* dl = new DirectorList();
	RatingSortedList() {
		start = NULL;
		ploc = NULL;
		loc = NULL;
		last = NULL;
	}


	void Parser() {
		ifstream csvFile("IMDB_Top5000-SEECS.csv");

		if (!csvFile.is_open()) {
			cout << "The File could not be found" << endl;
		}
		int count = 0;
		string line;
		getline(csvFile, line);
		string temp = "";
		string temp1 = "";
		for (int x = 0; x <= 5000; x++) {
			count++;
			getline(csvFile, line);
			stringstream lineStream(line);
			MovieNode* m = new MovieNode();
			DirectorNode* d = new DirectorNode();
			getline(lineStream, m->data.movie_title, '$');
			getline(lineStream, temp1, ',');
			cout << count << " " << m->data.movie_title << ",";
			getline(lineStream, m->data.genre, ',');
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.title_year = -1;
			else {
				m->data.title_year = stoi(temp);
				temp = "";
			}
			cout << m->data.title_year << ",";

			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.imdb_score = -1;
			else {
				m->data.imdb_score = stof(temp);
				temp = "";
			}
			getline(lineStream, d->data.director_name, ',');
			getline(lineStream, temp, ',');
			if (temp == "")
				d->data.director_facebook_likes = -1;
			else {
				d->data.director_facebook_likes = stoi(temp);
				temp = "";
			}

			DirectorNode* d2;
			d2 = dl->search(d);
			if (d2 == NULL) {
				m->data.director = d;
				dl->InsertSorted(d);
				d->data.moviesDirected->InsertSorted(m);
			}
			else {
				delete d;
				m->data.director = d2;
				d2->data.moviesDirected->InsertSorted(m);
			}


			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.num_critic_for_reviews = -1;
			else {
				m->data.num_critic_for_reviews = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.duration = -1;
			else {
				m->data.duration = stoi(temp);
				temp = "";
			}
			cout << "Duration:" << m->data.duration << ",";
			for (int j = 0; j <= 2; j++) {
				ActorNode* a = new ActorNode();
				ActorNode* a2;
				getline(lineStream, a->data.actor_name, ',');

				getline(lineStream, temp, ',');
				if (temp == "")
					a->data.actor_facebook_likes = -1;
				else {
					a->data.actor_facebook_likes = stoi(temp);
					temp = "";
				}
				cout << "Actor:" << a->data.actor_name << ",";

				a2 = al->search(a->data.actor_name);
				if (a2 == NULL) {
					m->data.actor[j] = a;
					al->InsertSorted(a);
					a->data.moviesActedIn->InsertSorted(m);
				}
				else {
					delete a;
					m->data.actor[j] = a2;
					a2->data.moviesActedIn->InsertSorted(m);
					a2 = NULL;
				}
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.gross = 0;
			else {
				m->data.gross = stol(temp);
				temp = "";
			}
			cout << "Gross:" << m->data.gross << ",";

			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.num_voted_users = -1;
			else {
				m->data.num_voted_users = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.cast_total_facebook_likes = -1;
			else {
				m->data.cast_total_facebook_likes = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.facenumber_in_poster = -1;
			else {
				m->data.facenumber_in_poster = stoi(temp);
				temp = "";
			}
			getline(lineStream, m->data.plot_keywords, ',');
			getline(lineStream, m->data.movie_imdb_link, ',');
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.num_user_for_reviews = -1;
			else {
				m->data.num_user_for_reviews = stoi(temp);
				temp = "";
			}
			getline(lineStream, m->data.language, ',');
			getline(lineStream, m->data.country, ',');
			getline(lineStream, m->data.content_rating, ',');
			cout << "Content Rating:" << m->data.content_rating << ",";

			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.budget = -1;
			else {
				m->data.budget = stoll(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.aspect_ratio = -1;
			else {
				m->data.aspect_ratio = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.movie_facebook_likes = -1;
			else {
				m->data.movie_facebook_likes = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.color = false;
			else {
				m->data.color = true;
				temp = "";
				cout << m->data.color << endl;
			}
			InsertSorted(m);
			//rml->InsertSorted(m);
			cout << endl;

		}

	}


	bool isEmpty() {
		if (start == NULL)
			return true;
		else
			return false;
	}
	void InsertAtFront(MovieNode* node) {

		if (isEmpty() == true) {
			start = node;
			last = node;
		}
		node->next = NULL;
		start = node;

	}
	void InsertAtEnd(MovieNode* node) {

		if (isEmpty()) {
			start = node;
			last = node;

		}
		last->next = NULL;
		last = node;
	}

	void insertvalueatmid(MovieNode* node) {

		node->next = ploc->next;
		ploc->next = node;
	};



	void InsertSorted(MovieNode* node) {
		Search(node->data.imdb_score);
		if (loc != NULL) {
			node->next = loc->next;
			loc->next = node;
		}
		else {
			if (loc == NULL && ploc == NULL)
				InsertAtFront(node);

			else
				if (ploc == last) {
					InsertAtEnd(node);
				}
				else if (ploc != NULL && loc == NULL)
					insertvalueatmid(node);
		}
	}
	void Search(float rating) {
		loc = start;
		ploc = NULL;
		while (loc != NULL && loc->data.imdb_score > rating) {
			ploc = loc;
			loc = loc->next;
		}
		if (loc != NULL)
			if (loc->data.imdb_score != rating)
				loc = NULL;
		return;
	}
	void Search_Genre_Rating(string g) {//func 13
		loc = start;
		ploc = NULL;

		while (loc != NULL) {
			if (loc->data.genre.find(g) != string::npos) {
				cout << loc->data.movie_title << endl;
				cout << loc->data.imdb_score << endl;

			}
			ploc = loc;
			loc = loc->next;
		}
	}
	void PrintChoice() {
		char option;
		cout << "Enter a to print highest to lowest and Enter b to print reverse: ";
		cin >> option;
		loc = start;
		switch (option) {
		case 'a':PrintList();
			break;
		case 'b':printReverse(loc);
		}
	}
	void PrintList() {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			cout << loc->data.movie_title << endl;
			cout << loc->data.imdb_score << endl;
			ploc = loc;
			loc = loc->next;
		}
	}
	void printReverse(MovieNode* temp) {
		if (temp == NULL)
			return;
		printReverse(temp->next);
		cout << temp->data.movie_title << endl;
		cout << temp->data.imdb_score << endl;

	}
};

class MovieList {
public:
	MovieNode* start;
	MovieNode* last;

	MovieNode* ploc;
	MovieNode* loc;
	ActorsList* al = new ActorsList();
	DirectorList* dl = new DirectorList();
	//RatingSortedList *rml = new RatingSortedList();
	MovieList() {
		start = NULL;
		ploc = NULL;
		loc = NULL;
		last = NULL;
	}
	void Parser() {
		ifstream csvFile("IMDB_Top5000-SEECS.csv");

		if (!csvFile.is_open()) {
			cout << "The File could not be found" << endl;
		}
		int count = 0;
		string line;
		getline(csvFile, line);
		string temp = "";
		string temp1 = "";
		for (int x = 0; x <= 5000; x++) {
			count++;
			MoviesDirected* mdnode = new MoviesDirected();
			getline(csvFile, line);
			stringstream lineStream(line);
			MovieNode* m = new MovieNode();
			DirectorNode* dnode = new DirectorNode();
			getline(lineStream, m->data.movie_title, '$');
			getline(lineStream, temp1, ',');
			cout << count << " " << m->data.movie_title << ",";
			getline(lineStream, m->data.genre, ',');
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.title_year = -1;
			else {
				m->data.title_year = stoi(temp);
				temp = "";
			}
			cout << m->data.title_year << ",";

			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.imdb_score = -1;
			else {
				m->data.imdb_score = stof(temp);
				temp = "";
			}
			cout << m->data.imdb_score;
			getline(lineStream, dnode->data.director_name, ',');
			getline(lineStream, temp, ',');
			if (temp == "")
				dnode->data.director_facebook_likes = -1;
			else {
				dnode->data.director_facebook_likes = stoi(temp);
				temp = "";
			}
			cout << "Director:" << dnode->data.director_name << ",";
			DirectorNode* d2;
			d2 = dl->search(dnode);
			if (d2 == NULL) {
				m->data.director = dnode;
				dl->InsertSorted(dnode);
				dnode->data.moviesDirected = mdnode;
				mdnode->InsertSorted(m);
				//	cout << "Director Name: " <<d->data.director_name<< "," << endl;
				//	d->data.moviesDirected->Printlist();

			}
			else if (d2->data.director_facebook_likes == dnode->data.director_facebook_likes) {
				delete dnode;
				delete mdnode;
				m->data.director = d2;
				d2->data.moviesDirected->InsertSorted(m);
				//	cout << "Director Name: " << d2->data.director_name << "," << endl;
				//	cout << "Director Movie: ";
				//	d2->data.moviesDirected->Printlists
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.num_critic_for_reviews = -1;
			else {
				m->data.num_critic_for_reviews = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.duration = -1;
			else {
				m->data.duration = stoi(temp);
				temp = "";
			}
			cout << "Duration:" << m->data.duration << ",";
			for (int j = 0; j <= 2; j++) {
				ActorNode* a = new ActorNode();
				MoviesActedIn* mai = new MoviesActedIn();
				ActorNode* a2;
				getline(lineStream, a->data.actor_name, ',');

				getline(lineStream, temp, ',');
				if (temp == "")
					a->data.actor_facebook_likes = -1;
				else {
					a->data.actor_facebook_likes = stoi(temp);
					temp = "";
				}
				cout << "Actor:" << a->data.actor_name << ",";

				a2 = al->search(a->data.actor_name);
				if (a2 == NULL) {
					m->data.actor[j] = a;
					al->InsertSorted(a);
					mai->InsertSorted(m);
					a->data.moviesActedIn = mai;
				}
				else {
					delete a;
					delete mai;
					m->data.actor[j] = a2;
					a2->data.moviesActedIn->InsertSorted(m);
					a2 = NULL;
				}
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.gross = 0;
			else {
				m->data.gross = stol(temp);
				temp = "";
			}
			cout << "Gross:" << m->data.gross << ",";

			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.num_voted_users = -1;
			else {
				m->data.num_voted_users = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.cast_total_facebook_likes = -1;
			else {
				m->data.cast_total_facebook_likes = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.facenumber_in_poster = -1;
			else {
				m->data.facenumber_in_poster = stoi(temp);
				temp = "";
			}
			getline(lineStream, m->data.plot_keywords, ',');
			getline(lineStream, m->data.movie_imdb_link, ',');
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.num_user_for_reviews = -1;
			else {
				m->data.num_user_for_reviews = stoi(temp);
				temp = "";
			}
			getline(lineStream, m->data.language, ',');
			getline(lineStream, m->data.country, ',');
			getline(lineStream, m->data.content_rating, ',');
			cout << "Content Rating:" << m->data.content_rating << ",";

			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.budget = -1;
			else {
				m->data.budget = stoll(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.aspect_ratio = -1;
			else {
				m->data.aspect_ratio = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.movie_facebook_likes = -1;
			else {
				m->data.movie_facebook_likes = stoi(temp);
				temp = "";
			}
			getline(lineStream, temp, ',');
			if (temp == "")
				m->data.color = false;
			else {
				m->data.color = true;
				temp = "";
				cout << m->data.color << endl;
			}

			InsertSorted(m);
			//rml->InsertSorted(m);
			cout << endl;
		}
	}

	bool isEmpty() {
		if (start == NULL)
			return true;
		else
			return false;
	}
	void InsertAtFront(MovieNode* node) {

		if (isEmpty() == true) {
			start = node;
			last = node;
		}
		node->next = NULL;
		start = node;

	}
	void InsertAtEnd(MovieNode* node) {

		if (isEmpty()) {
			start = node;
			last = node;

		}
		last->next = NULL;
		last = node;
	}

	void insertvalueatmid(MovieNode* node) {

		node->next = ploc->next;
		ploc->next = node;
	}



	void InsertSorted(MovieNode* node) {
		SearchMovieByYear(node->data.title_year);
		if (loc != NULL) {
			node->next = loc->next;
			loc->next = node;
		}
		else {
			if (loc == NULL && ploc == NULL)
				InsertAtFront(node);

			else
				if (ploc == last) {
					InsertAtEnd(node);
				}
				else if (ploc != NULL && loc == NULL)
					insertvalueatmid(node);
		}
	}

	void SearchMovie(MovieNode* m) {
		MovieNode* temp;
		loc = start;
		ploc = NULL;
		bool found = false;
		while (loc != NULL && found == false) {
			if (loc->data.movie_title == m->data.movie_title)
				found = true;

			ploc = loc;
			loc = loc->next;

			if (found == true) {
				cout << "title is: " << ploc->data.movie_title << endl;
				cout << "release year is : " << ploc->data.title_year << endl;
				cout << "rating is: " << ploc->data.content_rating << endl;
				cout << "duration is: " << ploc->data.duration << endl;
				cout << "director is: " << ploc->data.director->data.director_name << endl;
				cout << "actors are: " << endl;
				for (int i = 0; i < 3; i++) {
					cout << ploc->data.actor[i]->data.actor_name << endl;
				}
			}
			else
				cout << "not found" << endl;
		}
	}
	void  PrintMovieInYear(int year) {
		loc = start;
		ploc = NULL;
		while (loc != NULL) {
			if (loc->data.title_year == year) {
				cout << "title is: " << loc->data.movie_title << endl;
			}
			ploc = loc;
			loc = loc->next;
		}
		return;
	}
	void SearchMovieByYear(int year) {
		loc = start;
		ploc = NULL;
		while (loc != NULL && loc->data.title_year > year) {

			ploc = loc;
			loc = loc->next;
		}
		if (loc != NULL)
			if (loc->data.title_year != year)
				loc = NULL;
		return;
	}

	void SearchMovieByRating(int rating) {
		loc = start;
		ploc = NULL;
		while (loc != NULL && loc->data.imdb_score > rating) {
			ploc = loc;
			loc = loc->next;
		}
		if (loc != NULL)
			if (loc->data.imdb_score != rating)
				loc = NULL;
		return;
	}


	void PrintChoice() {//code for func 10
		char option;
		cout << "Enter a to print highest to lowest and Enter b to print reverse";
		cin >> option;
		loc = start;
		switch (option) {
		case 'a':PrintList();
			break;
		case 'b':printReverse(loc);
		}
	}
	void PrintList() {
		loc = start;
		ploc = NULL;

		while (loc != NULL) {
			cout << loc->data.movie_title << endl;
			cout << loc->data.title_year << endl;
			ploc = loc;
			loc = loc->next;
		}
	}

	void printReverse(MovieNode* temp) {
		if (temp == NULL)
			return;
		printReverse(temp->next);
		cout << temp->data.movie_title << endl;
		cout << temp->data.title_year << endl;
	}
	void Search_Genre_year(string g) {//func 11
		loc = start;
		ploc = NULL;

		while (loc != NULL) {
			if (loc->data.genre.find(g) != string::npos) {
				cout << loc->data.movie_title << endl;
				cout << loc->data.title_year << endl;

			}
			ploc = loc;
			loc = loc->next;


		}
	}
};
// Name : Danish Rasheed Cms : 309161
//Name : Abdullah Waseem Afzal CMS: 285607
//Class : BSCS-9A
int main()
{
	MovieList* ml = new MovieList();
	DirectorNode* d;
	RatingSortedList* rml = new RatingSortedList();
	string genre;
	char option;
	ml->Parser();
	ml->PrintChoice();
	return 0;
};