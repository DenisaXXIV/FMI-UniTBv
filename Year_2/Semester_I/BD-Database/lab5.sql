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
-- Name: Adresa; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Adresa" (
    "CodPostal" character varying NOT NULL,
    "Strada" character varying,
    "Localitate" character varying
);


ALTER TABLE public."Adresa" OWNER TO postgres;

--
-- Name: Client; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Client" (
    "ClientID" integer NOT NULL,
    "Firma" character varying,
    "Status" character varying,
    "AdresaID" character varying NOT NULL
);


ALTER TABLE public."Client" OWNER TO postgres;

--
-- Name: Client_ClientID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Client_ClientID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Client_ClientID_seq" OWNER TO postgres;

--
-- Name: Client_ClientID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Client_ClientID_seq" OWNED BY public."Client"."ClientID";


--
-- Name: Comanda; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Comanda" (
    "ComandaID" integer NOT NULL,
    "Data" date,
    "DataLivrare" date,
    "ClientID" integer NOT NULL
);


ALTER TABLE public."Comanda" OWNER TO postgres;

--
-- Name: Comanda_ClientID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Comanda_ClientID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Comanda_ClientID_seq" OWNER TO postgres;

--
-- Name: Comanda_ClientID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Comanda_ClientID_seq" OWNED BY public."Comanda"."ClientID";


--
-- Name: Comanda_ComandaID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Comanda_ComandaID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Comanda_ComandaID_seq" OWNER TO postgres;

--
-- Name: Comanda_ComandaID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Comanda_ComandaID_seq" OWNED BY public."Comanda"."ComandaID";


--
-- Name: Contine; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Contine" (
    "ContineID" integer NOT NULL,
    "ComandaID" integer NOT NULL,
    "ProdusID" integer NOT NULL,
    "Cantitate" double precision,
    "PretTotal" money
);


ALTER TABLE public."Contine" OWNER TO postgres;

--
-- Name: Contine_ComandaID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Contine_ComandaID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Contine_ComandaID_seq" OWNER TO postgres;

--
-- Name: Contine_ComandaID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Contine_ComandaID_seq" OWNED BY public."Contine"."ComandaID";


--
-- Name: Contine_ContineID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Contine_ContineID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Contine_ContineID_seq" OWNER TO postgres;

--
-- Name: Contine_ContineID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Contine_ContineID_seq" OWNED BY public."Contine"."ContineID";


--
-- Name: Contine_ProdusID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Contine_ProdusID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Contine_ProdusID_seq" OWNER TO postgres;

--
-- Name: Contine_ProdusID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Contine_ProdusID_seq" OWNED BY public."Contine"."ProdusID";


--
-- Name: Depozit; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Depozit" (
    "DepozitID" integer NOT NULL,
    "Localitate" character varying,
    "Strada" character varying
);


ALTER TABLE public."Depozit" OWNER TO postgres;

--
-- Name: Depozit_DepozitID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Depozit_DepozitID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Depozit_DepozitID_seq" OWNER TO postgres;

--
-- Name: Depozit_DepozitID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Depozit_DepozitID_seq" OWNED BY public."Depozit"."DepozitID";


--
-- Name: Produs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Produs" (
    "ProdID" integer NOT NULL,
    "Denumire" character varying,
    "Pret" money
);


ALTER TABLE public."Produs" OWNER TO postgres;

--
-- Name: Produs_ProdID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Produs_ProdID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Produs_ProdID_seq" OWNER TO postgres;

--
-- Name: Produs_ProdID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Produs_ProdID_seq" OWNED BY public."Produs"."ProdID";


--
-- Name: Stocat; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Stocat" (
    "StocatID" integer NOT NULL,
    "ProdID" integer NOT NULL,
    "Cantitate" double precision,
    "DepozitID" integer NOT NULL
);


ALTER TABLE public."Stocat" OWNER TO postgres;

--
-- Name: Stocat_DepozitID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Stocat_DepozitID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Stocat_DepozitID_seq" OWNER TO postgres;

--
-- Name: Stocat_DepozitID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Stocat_DepozitID_seq" OWNED BY public."Stocat"."DepozitID";


--
-- Name: Stocat_ProdID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Stocat_ProdID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Stocat_ProdID_seq" OWNER TO postgres;

--
-- Name: Stocat_ProdID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Stocat_ProdID_seq" OWNED BY public."Stocat"."ProdID";


--
-- Name: Stocat_StocatID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Stocat_StocatID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Stocat_StocatID_seq" OWNER TO postgres;

--
-- Name: Stocat_StocatID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Stocat_StocatID_seq" OWNED BY public."Stocat"."StocatID";


--
-- Name: Client ClientID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Client" ALTER COLUMN "ClientID" SET DEFAULT nextval('public."Client_ClientID_seq"'::regclass);


--
-- Name: Comanda ComandaID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comanda" ALTER COLUMN "ComandaID" SET DEFAULT nextval('public."Comanda_ComandaID_seq"'::regclass);


--
-- Name: Comanda ClientID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comanda" ALTER COLUMN "ClientID" SET DEFAULT nextval('public."Comanda_ClientID_seq"'::regclass);


--
-- Name: Contine ContineID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Contine" ALTER COLUMN "ContineID" SET DEFAULT nextval('public."Contine_ContineID_seq"'::regclass);


--
-- Name: Contine ComandaID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Contine" ALTER COLUMN "ComandaID" SET DEFAULT nextval('public."Contine_ComandaID_seq"'::regclass);


--
-- Name: Contine ProdusID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Contine" ALTER COLUMN "ProdusID" SET DEFAULT nextval('public."Contine_ProdusID_seq"'::regclass);


--
-- Name: Depozit DepozitID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Depozit" ALTER COLUMN "DepozitID" SET DEFAULT nextval('public."Depozit_DepozitID_seq"'::regclass);


--
-- Name: Produs ProdID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Produs" ALTER COLUMN "ProdID" SET DEFAULT nextval('public."Produs_ProdID_seq"'::regclass);


--
-- Name: Stocat StocatID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Stocat" ALTER COLUMN "StocatID" SET DEFAULT nextval('public."Stocat_StocatID_seq"'::regclass);


--
-- Name: Stocat ProdID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Stocat" ALTER COLUMN "ProdID" SET DEFAULT nextval('public."Stocat_ProdID_seq"'::regclass);


--
-- Name: Stocat DepozitID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Stocat" ALTER COLUMN "DepozitID" SET DEFAULT nextval('public."Stocat_DepozitID_seq"'::regclass);


--
-- Data for Name: Adresa; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Adresa" VALUES ('500470', 'Strada Albinelor', 'Brasov');
INSERT INTO public."Adresa" VALUES ('100001', 'Strada Podul Inalt', 'Ploiesti');
INSERT INTO public."Adresa" VALUES ('105200', 'Strada Republicii', 'Baicoi');


--
-- Data for Name: Client; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Client" VALUES (1, 'Elit', 'Activ', '100001');
INSERT INTO public."Client" VALUES (2, 'Pram', 'Activ', '105200');
INSERT INTO public."Client" VALUES (3, 'Coca-Cola', 'Activ', '500470');


--
-- Data for Name: Comanda; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Comanda" VALUES (1, '2021-02-12', '2021-02-15', 1);
INSERT INTO public."Comanda" VALUES (2, '2021-03-15', '2021-03-19', 2);
INSERT INTO public."Comanda" VALUES (3, '2021-08-22', '2021-08-23', 3);


--
-- Data for Name: Contine; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Contine" VALUES (1, 1, 3, 5, '$17.00');
INSERT INTO public."Contine" VALUES (2, 2, 2, 6, '$12.60');
INSERT INTO public."Contine" VALUES (3, 3, 1, 3, '$13.50');


--
-- Data for Name: Depozit; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Depozit" VALUES (1, 'Brasov', 'Strada Albinelor ');
INSERT INTO public."Depozit" VALUES (2, 'Ploiesti', 'Strada Podul Inalt');
INSERT INTO public."Depozit" VALUES (3, 'Targoviste', 'Strada Mincu Ion');


--
-- Data for Name: Produs; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Produs" VALUES (1, 'Lapte 2L', '$4.50');
INSERT INTO public."Produs" VALUES (2, 'Unt', '$2.10');
INSERT INTO public."Produs" VALUES (3, 'Zahar Margaritar', '$3.40');


--
-- Data for Name: Stocat; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Stocat" VALUES (1, 1, 2, 1);
INSERT INTO public."Stocat" VALUES (2, 2, 0, 2);
INSERT INTO public."Stocat" VALUES (3, 3, 5, 3);


--
-- Name: Client_ClientID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Client_ClientID_seq"', 3, true);


--
-- Name: Comanda_ClientID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Comanda_ClientID_seq"', 1, false);


--
-- Name: Comanda_ComandaID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Comanda_ComandaID_seq"', 3, true);


--
-- Name: Contine_ComandaID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Contine_ComandaID_seq"', 1, false);


--
-- Name: Contine_ContineID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Contine_ContineID_seq"', 3, true);


--
-- Name: Contine_ProdusID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Contine_ProdusID_seq"', 1, false);


--
-- Name: Depozit_DepozitID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Depozit_DepozitID_seq"', 3, true);


--
-- Name: Produs_ProdID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Produs_ProdID_seq"', 3, true);


--
-- Name: Stocat_DepozitID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Stocat_DepozitID_seq"', 1, false);


--
-- Name: Stocat_ProdID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Stocat_ProdID_seq"', 1, false);


--
-- Name: Stocat_StocatID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Stocat_StocatID_seq"', 3, true);


--
-- Name: Adresa Adresa_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Adresa"
    ADD CONSTRAINT "Adresa_pkey" PRIMARY KEY ("CodPostal");


--
-- Name: Client Client_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Client"
    ADD CONSTRAINT "Client_pkey" PRIMARY KEY ("ClientID");


--
-- Name: Comanda Comanda_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comanda"
    ADD CONSTRAINT "Comanda_pkey" PRIMARY KEY ("ComandaID");


--
-- Name: Contine Contine_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Contine"
    ADD CONSTRAINT "Contine_pkey" PRIMARY KEY ("ContineID");


--
-- Name: Depozit Depozit_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Depozit"
    ADD CONSTRAINT "Depozit_pkey" PRIMARY KEY ("DepozitID");


--
-- Name: Produs Produs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Produs"
    ADD CONSTRAINT "Produs_pkey" PRIMARY KEY ("ProdID");


--
-- Name: Stocat Stocat_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Stocat"
    ADD CONSTRAINT "Stocat_pkey" PRIMARY KEY ("StocatID");


--
-- Name: Client Client_Adresa_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Client"
    ADD CONSTRAINT "Client_Adresa_fkey" FOREIGN KEY ("AdresaID") REFERENCES public."Adresa"("CodPostal") NOT VALID;


--
-- Name: Comanda Comanda_Client_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comanda"
    ADD CONSTRAINT "Comanda_Client_fkey" FOREIGN KEY ("ClientID") REFERENCES public."Client"("ClientID");


--
-- Name: Contine Comanda_Contine_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Contine"
    ADD CONSTRAINT "Comanda_Contine_fkey" FOREIGN KEY ("ComandaID") REFERENCES public."Comanda"("ComandaID") NOT VALID;


--
-- Name: Contine Contine_Produs_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Contine"
    ADD CONSTRAINT "Contine_Produs_fkey" FOREIGN KEY ("ProdusID") REFERENCES public."Produs"("ProdID") NOT VALID;


--
-- Name: Stocat Produs_Stocat_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Stocat"
    ADD CONSTRAINT "Produs_Stocat_fkey" FOREIGN KEY ("ProdID") REFERENCES public."Produs"("ProdID");


--
-- Name: Stocat Stocat_Depozit_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Stocat"
    ADD CONSTRAINT "Stocat_Depozit_fkey" FOREIGN KEY ("DepozitID") REFERENCES public."Depozit"("DepozitID") NOT VALID;

-- Afisarea listei de comenzi a unui client.
SELECT "ComandaID", "Data", "DataLivrare", "ClientID"
	FROM public."Comanda"
	WHERE "ClientID"=1;

-- Calcularea sumei pe care o are de achitat fiecare client.
SELECT SUM(public."Contine"."PretTotal")
	FROM public."Contine"
	JOIN public."Comanda"
	ON public."Comanda"."ComandaID"=public."Contine"."ComandaID"
	WHERE public."Comanda"."ClientID"=1  ;

-- Afisarea listei de produse epuizate.
SELECT public."Stocat"."StocatID",public."Produs"."Denumire", public."Depozit"."Localitate"
	FROM public."Stocat"
	JOIN public."Produs"
	ON public."Stocat"."ProdID"=public."Produs"."ProdID"
	JOIN public."Depozit"
	ON public."Stocat"."DepozitID"=public."Depozit"."DepozitID"
	WHERE "Cantitate"=0;

-- Afisarea listei de produse dintr-un depozit.
SELECT public."Stocat"."StocatID",public."Produs"."Denumire", public."Depozit"."Localitate"
	FROM public."Stocat"
	JOIN public."Produs"
	ON public."Stocat"."ProdID"=public."Produs"."ProdID"
	JOIN public."Depozit"
	ON public."Stocat"."DepozitID"=public."Depozit"."DepozitID";


--
-- PostgreSQL database dump complete
--

