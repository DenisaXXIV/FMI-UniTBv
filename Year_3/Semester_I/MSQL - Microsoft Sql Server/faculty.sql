CREATE DATABASE Faculty;

CREATE TABLE GroupeType(
	GroupeTypeId int IDENTITY(1,1) PRIMARY KEY,
    ShortName nvarchar(4) NOT NULL,
	FullName nvarchar(25) NOT NULL,
	Active bit NOT NULL DEFAULT 1
 );

CREATE TABLE Groupe(
	GroupeId int IDENTITY(1,1) PRIMARY KEY,
	GroupeTypeId int NOT NULL FOREIGN KEY REFERENCES GroupeType(GroupeTypeId),
	FullName nvarchar(25) NOT NULL,
	Active bit NOT NULL DEFAULT 1
 );

CREATE TABLE Student(
	StudentId int IDENTITY(1,1) PRIMARY KEY,
    GroupeId int NOT NULL FOREIGN KEY REFERENCES Groupe(GroupeId),
	FirstName nvarchar(25) NOT NULL,
	LastName nvarchar(25) NOT NULL,
	CNP nvarchar(13) NOT NULL,
	Mail nvarchar(100) NULL,
	Active bit NOT NULL DEFAULT 1
 );

CREATE TABLE Professor(
	ProfessorId int IDENTITY(1,1) PRIMARY KEY,
	FirstName nvarchar(25) NOT NULL,
	LastName nvarchar(25) NOT NULL,
	Cnp nvarchar(13) NOT NULL,
	EmploymentYear int NOT NULL,
	Active bit NOT NULL DEFAULT 1
 );

CREATE TABLE SubjectType(
	SubjectTypeId int IDENTITY(1,1) PRIMARY KEY,
    ShortName nvarchar(4) NOT NULL,
	FullName nvarchar(25) NOT NULL,
	Active bit NOT NULL DEFAULT 1
 );

CREATE TABLE Subject(
	SubjectId int IDENTITY(1,1) PRIMARY KEY,
	SubjectTypeId int NOT NULL FOREIGN KEY REFERENCES SubjectType(SubjectTypeId),
    ShortName nvarchar(4) NOT NULL,
	FullName nvarchar(25) NOT NULL,
	Active bit NOT NULL DEFAULT 
 );

CREATE TABLE ProfessorSubject(
	ProfessorSubjectId int IDENTITY(1,1) PRIMARY KEY,
	ProfessorId int NOT NULL FOREIGN KEY REFERENCES Professor(ProfessorId),
	SubjectId int NOT NULL FOREIGN KEY REFERENCES Subject(SubjectId),
 );

CREATE TABLE Note(
	NoteId int IDENTITY(1,1) PRIMARY KEY,
	ProfessorId int NOT NULL FOREIGN KEY REFERENCES Professor(ProfessorId),
	SubjectId int NOT NULL FOREIGN KEY REFERENCES Subject(SubjectId),
	StudentId  int NOT NULL FOREIGN KEY REFERENCES Student(StudentId ),
	Grade int NOT NULL CHECK (Grade<=10),
	ExamDate DATETIME NOT NULL  DEFAULT GETDATE() 
 );