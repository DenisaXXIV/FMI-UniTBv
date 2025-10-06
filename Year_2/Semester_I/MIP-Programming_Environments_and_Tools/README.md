# MIP - Programming Environments and Tools

You may use these materials as long as you mention the source and the author. <br>
Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## Exam subject:

A container consists of elements and has a fixed (unchangeable) size. A client searches for an item in the container, if it finds it, it returns it with its details (which are also kept in the container), if it does not find it, puts it in the container along with its details. If the container is full, it will remove the item with the fewest accesses from the container, and if there are several such items, the one that has been accessed the most is the last one.

*maximum container size: 7

## Final Project

### Competie

A full-stack Java application as learning material to learn:

- Java, SQL, FXML, JSON
- TCE sockets, Threads
- Intellij IDEA
- PostgreSQL
- JavaFX
- Scene Builder
- Maven

#### Problem Statement

Competitors participate in a competition. Each competitor is part of a team (one and only one). A team can have between a minimum of 2 and a maximum of 5 competitors. The competition administrator plans the stages (each stage is attended by competitors, not teams). At the end of each stage, the participating competitors register a score (which does not have to be unique compared to the rest of the participants in the stage). Only the competitor can register his own score (not the administrator) and cannot be modified. A stage is considered completed after all registered competitors pass the corresponding score. The administrator can communicate to the candidates who did not register their score to do so.

Each competitor, but also the administrator, can see the ranking according to the stages already completed (those that have all the scores), individually and in teams. In one stage the 1st place receives 10 points, the 2nd place, 6 points, the 3rd place, 3 points, the 4th place, one point. if there are several competitors on the same place, each one will receive the arithmetic mean of the cumulative score for the places.

#### Functional Requests

- login
- competitor registration and validation (from keyboard, csv, xml or json)
- team registration and validation (2-5 unique competitors)
- registration and validation of competitors in the team
- score registration (validation -> notification sent to competitor)
- check if all competitors have entered their score
- ranking display (individual and team)

#### Database Scheme

<img title="" src="file:///D:/Proiecte/FMI-UniTBv/Year_2/Semester_I/MIP-Programming_Environments_and_Tools/Competie/Images/db.png" alt="" width="491" data-align="left">

##### Use Cases

| <img title="" src="file:///D:/Proiecte/FMI-UniTBv/Year_2/Semester_I/MIP-Programming_Environments_and_Tools/Competie/Images/admin_actor.png" alt="" width="51" data-align="left"> | - logs in <br/>- registers and manages competitors <br/>- registers and manages teams <br/>- plans the stages <br/>- sends notifications <br/>- views the ranking |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| <img title="" src="file:///D:/Proiecte/FMI-UniTBv/Year_2/Semester_I/MIP-Programming_Environments_and_Tools/Competie/Images/competitor_actor.png" alt="" width="68">              | **- logs in<br/>- records his score<br/>- receives notification from admin<br/>- can view the ranking (both the competitor and the team)**                        |

<sub>I hope that this repository helped you, for more details about me, you can access my website: [here](https://denisa-vasile.info/).</sub>
