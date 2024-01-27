--1.Write SQL query to create the above tables

CREATE TABLE DEPARTMENT (
    ID INT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Location VARCHAR(255)
);

CREATE TABLE EMPLOYEE (
    ID INT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    DepartmentID INT,
    ManagerID INT,
    Salary DECIMAL(10, 2),
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(ID),
    FOREIGN KEY (ManagerID) REFERENCES EMPLOYEE(ID)
);


--2. Add the keys and indexes for the above table

For the tables provided, the primary keys have already been added in the creation query. If you want to add additional indexes or constraints, you can do so using ALTER TABLE commands.

--3. Write SQL query to insert the data given
 
--Inserting data into DEPARTMENT table
INSERT INTO DEPARTMENT (ID, Name, Location) VALUES
(1, 'Engineering', 'Bangalore'),
(2, 'Sales', 'Delhi'),
(3, 'Operations', 'Delhi'),
(4, 'Product', 'Bangalore'),
(5, 'Production', 'Hyderabad');

Inserting data into EMPLOYEE table
--INSERT INTO EMPLOYEE (ID, Name, DepartmentID, ManagerID, Salary) VALUES
(1, 'Ram', 1, NULL, 200000),
(2, 'Vimal', 1, 1, 150000),
(3, 'Albert', 1, 1, 100000),
(4, 'John', 2, NULL, 200000),
(5, 'Taj', 2, 4, 100000),
(6, 'Deepak', 2, 4, 75000),
(7, 'Raju', 3, NULL, 100000),
(8, 'Ramesh', 3, 7, 50000),
(9, 'Jyoti', 4, NULL, 200000),
(10, 'Prince', 5, NULL, 200000);


--4. Write SQL query to list department wise employee count at each location

SELECT d.Name AS DEPARTMENT, d.Location, COUNT(e.ID) AS Employee_Count
FROM DEPARTMENT d
LEFT JOIN Employee e ON d.ID = e.DEPARTMENT
GROUP BY d.ID, d.Name, d.Location;

--5. Write SQL query to calculate and list the average salary of employees under each manager
SELECT Manager, AVG(Salary) AS Average_Salary
FROM EMPLOYEE
WHERE Manager IS NOT NULL
GROUP BY Manager;
