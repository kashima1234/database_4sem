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
	publish_id int references publish(id),
	title varchar not null,
	publish_year int,
	count int
);

create table authorship (
	id serial primary key,
	book_id int references book(id),
	author_id int references author(id)
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
	abonent_id int references abonent(id),
	book_id int references book(id),
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
	book_id int references book(id),
	category_id int references category(id)
);