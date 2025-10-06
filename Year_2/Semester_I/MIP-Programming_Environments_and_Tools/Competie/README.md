# Competie

A full-stack Java application as learning material to learn:
<ul>
  <li>Java, SQL, FXML, JSON</li>
  <li>TCE sockets, Threads</li>
  <li>Intellij IDEA</li>
  <li>PostgreSQL</li>
  <li>JavaFX</li>
  <li>Scene Builder</li>
  <li>Maven</li></ul>


## Problem Statement

Competitors participate in a competition. Each competitor is part of a team (one and only one). A team can have between a minimum of 2 and a maximum of 5 competitors. The competition administrator plans the stages (each stage is attended by competitors, not teams). At the end of each stage, the participating competitors register a score (which does not have to be unique compared to the rest of the participants in the stage). Only the competitor can register his own score (not the administrator) and cannot be modified. A stage is considered completed after all registered competitors pass the corresponding score. The administrator can communicate to the candidates who did not register their score to do so.

Each competitor, but also the administrator, can see the ranking according to the stages already completed (those that have all the scores), individually and in teams. In one stage the 1st place receives 10 points, the 2nd place, 6 points, the 3rd place, 3 points, the 4th place, one point. if there are several competitors on the same place, each one will receive the arithmetic mean of the cumulative score for the places. 

## Functional Requests

<ul>
  <li>login</li>
  <li>competitor registration and validation (from keyboard, csv, xml or json)</li>
  <li>team registration and validation (2-5 unique competitors)</li>
  <li>registration and validation of competitors in the team</li>
  <li>score registration (validation -> notification sent to competitor)</li>
  <li>check if all competitors have entered their score</li>
  <li>ranking display (individual and team) </li>
</ul>

## Database Scheme

<img src="https://github.com/DenisaXXIV/Competie/blob/master/Images/db.png" height="500px">

## Use Cases

<img src="https://github.com/DenisaXXIV/Competie/blob/master/Images/admin_actor.png" height="100px">
<ul>
  <li>logs in</li>
  <li>registers and manages competitors</li>
  <li>registers and manages teams</li>
  <li>plans the stages</li>
  <li>sends notifications</li>
  <li>views the ranking</li>
</ul>

<img src="https://github.com/DenisaXXIV/Competie/blob/master/Images/competitor_actor.png" height="100px">
<ul>
  <li>logs in</li>
  <li>records his score</li>
  <li>receives notification from admin</li>
  <li>can view the ranking (both the competitor and the team)</li>
</ul>

## Now, let's see the app :)

<br>

|      Profesor curs           |                Profesor laborator                            |                       Materie                     |
|------------------------------|--------------------------------------------------------------|---------------------------------------------------|
|   Dumitrescu Silviu-Razvan   |     [Rîtan Mihai-Lucian](https://github.com/RitanMihai)      |       Medii si Instrumente de Programare (MIP)    |

<sub> Alte materiale faculate: [click aici](https://github.com/DenisaXXIV/FMI-UniTBv#)</sub>
