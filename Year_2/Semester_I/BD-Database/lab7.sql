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
c_id integer primary key,
p_id integer 

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

CREATE TABLE Z_Employee(
e_id integer primary key,
p_id integer 

);
Alter table z_address add foreign key (zip) references z_City(zip );
Alter table z_person add foreign key (address_id) references z_address (address_id);
Alter table z_restaurant add foreign key (address_id) references z_address (address_id);
Alter table z_invoice add foreign key (u_id) references z_restaurant (u_id );
Alter table z_invoice add constraint FK_pers_inv foreign key (p_id_emp) references z_person (p_id) on delete cascade on update cascade;
Alter table z_invoice add constraint FK_pers_inv_idem foreign key (p_id_cust) references z_person (p_id) on delete cascade on update cascade;
Alter table z_invoice_articles add foreign key (invoice_no) references z_invoice (invoice_no);
Alter table z_invoice_articles add foreign key ( article_id ) references z_article ( article_id );
Alter table z_customer add constraint FK_pers_cust foreign key (p_id) references z_Person(p_id) on delete cascade on update cascade;
Alter table z_employee add constraint FK_pers_empl foreign key (p_id) references z_Person(p_id) on delete cascade on update cascade;
Insert into Z_City VALUES (8151,'Brasov');
Insert into Z_City VALUES (8040,'Bucuresti');
Insert into Z_City VALUES (1020,'Wien');
Insert into Z_Address VALUES (1,'Iuliu Maniu',8151,3);
Insert into Z_Address VALUES (2,'Rosiorilor',8040,10);
Insert into Z_Address VALUES (3,'Taubstummengasse',1020,11);
Insert into Z_Person VALUES (1,'Clark','Kent','M',3,'Employee');
Insert into Z_Person VALUES (2,'Lois','Lane','F',2,'Customer');
Insert into Z_Person VALUES (3,'Bugs','Bunny','M',2,'Employee');
Insert into Z_Person VALUES (4,'Indiana','Jones','M',2,'Customer');
Insert into Z_Person VALUES (5,'Marie','Antoinette','F',3, 'Employee');
Insert into Z_Person VALUES (6,'Janet','Jackson','F',1,'Customer');
Insert into Z_Customer VALUES (2);
Insert into Z_Customer VALUES (4);
Insert into Z_Customer VALUES (6);
Insert into Z_Employee VALUES (1);
Insert into Z_Employee VALUES (3);
Insert into Z_Employee VALUES (5);
Insert into Z_Restaurant VALUES(123456,'Cafe 23','03458720','031541756',1);
Insert into Z_Restaurant VALUES (234567,'Wan Tan','0542610','03154756',2);
Insert into Z_Restaurant VALUES(345678,'Times','08745220','03451556',3);
Insert into Z_Invoice VALUES(1111,'2010-10-10','14:00:00',123456,1,2);
Insert into Z_Invoice VALUES(2222,'2010-12-15','14:00:00',234567,3,4);
Insert into Z_Invoice VALUES(3333,'2011-03-06','14:00:00',345678,5,6);
Insert into Z_Article VALUES (4321,'Cola',3,0.3);
Insert into Z_Article VALUES (4322,'Fanta',10,2);
Insert into Z_Article VALUES (4323,'Pepsi',2,0.6);
Insert into Z_Invoice_Articles VALUES (1111,4321,3,0.3);
Insert into Z_Invoice_Articles VALUES (2222,4322,10,2);
Insert into Z_Invoice_Articles VALUES (3333,4323,8,0.8); 

Alter table z_person add constraint const_sex_enum check (sex in ('F','M')); 

UPDATE z_person
SET first_name='Livia', surname='Popa'
WHERE p_id=4 

DELETE FROM Z_Person
WHERE p_id=3 

CREATE INDEX index1
ON z_person(first_name,surname)
DECLARE @c INT=7
WHILE @c<1000000
Begin
INSERT INTO Z_Person
VALUES(@c,'nume'+CAST(@c AS varchar), 'prenume'+CAST(@c as varchar),'M',1,'Employee');
INSERT INTO Z_Person
VALUES (@c+1,'nume'+CAST(@c+1 AS varchar), 'prenume'+CAST(@c+1 as varchar),'F',2,'Customer');
SET @c+=2;
END 

declare @t1 int = datepart(MILLISECOND, GETDATE())
SELECT * FROM Z_Person
WHERE first_name='nume10000' and surname='prenume10000'
declare @t2 int =  datepart(MILLISECOND, GETDATE())
select DATEDIFF(MILLISECOND, @t1, @t2)