CREATE DATABASE Z_restaurant
    WITH 
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'English_United States.1250'
    LC_CTYPE = 'English_United States.1250'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1;

CREATE TABLE Z_Address (
Address_id integer primary key,
Street VARCHAR(50),
zip integer,
house_number integer
);

CREATE TABLE Z_City (
Zip integer primary key,
City VARCHAR(50)
);

CREATE TABLE Z_Person (
p_id integer primary key,
first_name VARCHAR(50),
surname VARCHAR(50),
sex char,
address_id integer,
category VARCHAR(50)
);
CREATE TABLE Z_Customer (
p_id integer primary key
);

CREATE TABLE Z_Restaurant (
U_id integer primary key,
name VARCHAR(50),
phone VARCHAR(30),
fax VARCHAR(30),
address_id integer
);

CREATE TABLE Z_Invoice (
invoice_no integer primary key,
date1 date,
time1 VARCHAR(50),
u_id integer,
p_id_emp integer,
p_id_cust integer
);

CREATE TABLE Z_Article (
article_id integer primary key,
name VARCHAR(50),
price integer,
vat integer
);

CREATE TABLE Z_Invoice_Articles (
invoice_no integer,
article_id integer,
price integer,
vat integer,
primary key (invoice_no, article_id)
);

Alter table address add foreign key (zip) references City(zip );
Alter table person add foreign key (address_id) references address (address_id);
Alter table restaurant add foreign key (address_id) references address (address_id);
Alter table invoice add foreign key (uid) references restaurant (uid );
Alter table invoice add foreign key (p_id_emp) references person (p_id);
Alter table invoice add foreign key (p_id_cust) references person (p_id);
Alter table invoice_articles add foreign key (invoice_no) references invoice (invoice_no);
Alter table invoice_articles add foreign key ( article_id ) references article ( article_id );
Alter table customer add foreign key (p_id) references Person(p_id);
Alter table employee add foreign key (p_id) references Person(p_id);

Insert into Z_City VALUES (8151,’Brasov’);
Insert into Z_City VALUES (8040,’Bucuresti’);
Insert into Z_City VALUES (1020,’Wien’);
Insert into Z_Address VALUES (1,’Iuliu Maniu’,8151,3);
Insert into Z_Address VALUES (2,’Rosiorilor’,8040,10);
Insert into Z_Address VALUES (3,’Taubstummengasse’,1020,11);
Insert into Z_Person VALUES (1,’Clark’,’Kent’,’M’,3,’Employee’);
Insert into Z_Person VALUES (2,’Lois’,’Lane’,’F’,2, ’Customer’);
Insert into Z_Person VALUES (3,’Bugs’,’Bunny’,’M’,2,’Employee’);
Insert into Z_Person VALUES (4,’Indiana’,’Jones’,’M’,2,’Customer’);
Insert into Z_Person VALUES (5,’Marie’,’Antoinette’,’F’,3, ’Employee’);
Insert into Z_Person VALUES (6,’Janet’,’Jackson’,’F’,1,’Customer’);
Insert into Z_Customer VALUES (2);
Insert into Z_Customer VALUES (4);
Insert into Z_Customer VALUES (6);
Insert into Z_Employee VALUES (1);
Insert into Z_Employee VALUES (3);
Insert into Z_Employee VALUES (5);
Insert into Z_Restaurant VALUES(123456,’Cafe 23’,’03458720’,’031541756’,1);
Insert into Z_Restaurant VALUES (234567,’Wan Tan’,’0542610’,’03154756’,2);
Insert into Z_Restaurant VALUES(345678,’Times’,’08745220’,’03451556’,3);
Insert into Z_Invoice VALUES(1111,to_date(’10.10.2010’,’dd.mm.yyyy’),’14:00:00’,123456,1,2);
Insert into Z_Invoice VALUES(2222,to_date(’15.12.2010’,’dd.mm.yyyy’),’14:00:00’,234567,3,4);
Insert into Z_Invoice VALUES(3333,to_date(’06.03.2011’,’dd.mm.yyyy’),’14:00:00’,345678,5,6);
Insert into Z_Article VALUES (4321,’Cola’,3,0.3);
Insert into Z_Article VALUES (4322,’Fanta’,10,2);
Insert into Z_Article VALUES (4323,’Pepsi’,2,0.6);
Insert into Z_Invoice_Articles VALUES (1111,4321,3,0.3);
Insert into Z_Invoice_Articles VALUES (2222,4322,10,2);
Insert into Z_Invoice_Articles VALUES (3333,4323,8,0.8);