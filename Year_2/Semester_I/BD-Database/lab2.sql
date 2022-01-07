--
-- PostgreSQL database dump
--

-- Dumped from database version 14.0
-- Dumped by pg_dump version 14.0

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: Address; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Address" (
    adr_id integer NOT NULL,
    street character varying,
    zip character varying NOT NULL,
    house_number integer
);


ALTER TABLE public."Address" OWNER TO postgres;

--
-- Name: Adresa_adr_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Adresa_adr_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Adresa_adr_id_seq" OWNER TO postgres;

--
-- Name: Adresa_adr_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Adresa_adr_id_seq" OWNED BY public."Address".adr_id;


--
-- Name: City; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."City" (
    zip character varying NOT NULL,
    city character varying NOT NULL
);


ALTER TABLE public."City" OWNER TO postgres;

--
-- Name: Person; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Person" (
    p_id integer NOT NULL,
    surname character varying,
    first_name character varying,
    sex "char",
    birthday date,
    adr_id integer NOT NULL
);


ALTER TABLE public."Person" OWNER TO postgres;

--
-- Name: Person_adr_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Person_adr_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Person_adr_id_seq" OWNER TO postgres;

--
-- Name: Person_adr_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Person_adr_id_seq" OWNED BY public."Person".adr_id;


--
-- Name: Person_p_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Person_p_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Person_p_id_seq" OWNER TO postgres;

--
-- Name: Person_p_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Person_p_id_seq" OWNED BY public."Person".p_id;


--
-- Name: Restaurant; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Restaurant" (
    r_id integer NOT NULL,
    name character varying,
    phone character varying,
    fax character varying,
    adr_id integer NOT NULL
);


ALTER TABLE public."Restaurant" OWNER TO postgres;

--
-- Name: Restaurant_adr_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Restaurant_adr_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Restaurant_adr_id_seq" OWNER TO postgres;

--
-- Name: Restaurant_adr_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Restaurant_adr_id_seq" OWNED BY public."Restaurant".adr_id;


--
-- Name: Restaurant_r_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Restaurant_r_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Restaurant_r_id_seq" OWNER TO postgres;

--
-- Name: Restaurant_r_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Restaurant_r_id_seq" OWNED BY public."Restaurant".r_id;


--
-- Name: Address adr_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Address" ALTER COLUMN adr_id SET DEFAULT nextval('public."Adresa_adr_id_seq"'::regclass);


--
-- Name: Person p_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Person" ALTER COLUMN p_id SET DEFAULT nextval('public."Person_p_id_seq"'::regclass);


--
-- Name: Person adr_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Person" ALTER COLUMN adr_id SET DEFAULT nextval('public."Person_adr_id_seq"'::regclass);


--
-- Name: Restaurant r_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Restaurant" ALTER COLUMN r_id SET DEFAULT nextval('public."Restaurant_r_id_seq"'::regclass);


--
-- Name: Restaurant adr_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Restaurant" ALTER COLUMN adr_id SET DEFAULT nextval('public."Restaurant_adr_id_seq"'::regclass);


--
-- Data for Name: Address; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Address" VALUES (1, 'Strada Albinelor ', '500470', 16);
INSERT INTO public."Address" VALUES (2, 'Strada Podul Inalt', '100001', 32);
INSERT INTO public."Address" VALUES (3, 'Strada Mincu Ion', '011357', 21);
INSERT INTO public."Address" VALUES (4, 'Strada Republicii', '105200', 57);
INSERT INTO public."Address" VALUES (5, 'Strada Madrid', '130002', 8);


--
-- Data for Name: City; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."City" VALUES ('500470', 'Brasov');
INSERT INTO public."City" VALUES ('100001', 'Ploiesti');
INSERT INTO public."City" VALUES ('011357', 'Bucuresti');
INSERT INTO public."City" VALUES ('105200', 'Baicoi');
INSERT INTO public."City" VALUES ('130002', 'Targoviste');


--
-- Data for Name: Person; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Person" VALUES (1, 'Gheorghe', 'Alexandru', 'M', '1986-02-12', 2);
INSERT INTO public."Person" VALUES (2, 'Duduță', 'Adrian', 'M', '1985-03-15', 3);
INSERT INTO public."Person" VALUES (3, 'Leoveanu', 'Daniel', 'M', '1992-05-15', 2);
INSERT INTO public."Person" VALUES (4, 'Cernamoriț', 'Emil', 'M', '1981-08-22', 4);
INSERT INTO public."Person" VALUES (5, 'Bota', 'Adina', 'F', '1978-03-07', 5);


--
-- Data for Name: Restaurant; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Restaurant" VALUES (1, 'D&G', '0725667770', '0241618299', 1);
INSERT INTO public."Restaurant" VALUES (2, 'Jerrys Pizza', '0372419833', '0241618299', 2);
INSERT INTO public."Restaurant" VALUES (3, 'Jamaica', ' 0372419889', '0372416808', 3);
INSERT INTO public."Restaurant" VALUES (4, 'Taverna Ursului', ' 0372416204', ' 0372416213', 4);
INSERT INTO public."Restaurant" VALUES (5, 'Big Belly', '0241751299', '0241751299', 5);


--
-- Name: Adresa_adr_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Adresa_adr_id_seq"', 5, true);


--
-- Name: Person_adr_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Person_adr_id_seq"', 1, false);


--
-- Name: Person_p_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Person_p_id_seq"', 5, true);


--
-- Name: Restaurant_adr_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Restaurant_adr_id_seq"', 1, false);


--
-- Name: Restaurant_r_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Restaurant_r_id_seq"', 5, true);


--
-- Name: Address Address_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Address"
    ADD CONSTRAINT "Address_pkey" PRIMARY KEY (adr_id);


--
-- Name: City City_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."City"
    ADD CONSTRAINT "City_pkey" PRIMARY KEY (zip);


--
-- Name: Person Person_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Person"
    ADD CONSTRAINT "Person_pkey" PRIMARY KEY (p_id);


--
-- Name: Restaurant Restaurant_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Restaurant"
    ADD CONSTRAINT "Restaurant_pkey" PRIMARY KEY (r_id);


--
-- Name: Address City_Address_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Address"
    ADD CONSTRAINT "City_Address_fkey" FOREIGN KEY (zip) REFERENCES public."City"(zip) NOT VALID;


--
-- Name: Person Person_Address_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Person"
    ADD CONSTRAINT "Person_Address_fkey" FOREIGN KEY (adr_id) REFERENCES public."Address"(adr_id);


--
-- Name: Restaurant Restaurant_Address_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Restaurant"
    ADD CONSTRAINT "Restaurant_Address_fkey" FOREIGN KEY (adr_id) REFERENCES public."Address"(adr_id);


--
-- PostgreSQL database dump complete
--

