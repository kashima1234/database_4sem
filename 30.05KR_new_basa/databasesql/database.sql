create table author (
	id serial primary key,
	family varchar not null,
	name varchar not null,
	patronymic varchar not null,
	birth_date date,
	death_date date
);

create table publish (
	id serial primary key,
	title varchar not null,
	description varchar
);

create table book (
	id serial primary key,
	publish_id int references publish(id) ON DELETE CASCADE NOT NULL,
	title varchar not null,
	publish_year int,
	count int
);

create table authorship (
	id serial primary key,
	book_id int references book(id) ON DELETE CASCADE NOT NULL,
	author_id int references author(id) ON DELETE CASCADE NOT NULL
);

create table abonent (
	id serial primary key,
	family varchar not null,
	name varchar not null,
	patronymic varchar not null,
	birth_date date
);

create table record (
	id serial primary key,
	abonent_id int references abonent(id) ON DELETE CASCADE NOT NULL,
	book_id int references book(id) ON DELETE CASCADE NOT NULL,
	taken_date date,
	return_date date
);

create table category (
	id serial primary key,
	title varchar,
	description varchar
);

create table book_category (
	id serial primary key,
	book_id int references book(id) ON DELETE CASCADE NOT NULL,
	category_id int references category(id) ON DELETE CASCADE NOT NULL
);