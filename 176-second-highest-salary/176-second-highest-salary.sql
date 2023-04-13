/* Write your PL/SQL query statement below */

select max(Salary) as SecondHighestSalary from 
Employee where 
salary < ( select max(Salary)
from Employee )




-- SELECT max(Salary) as SecondHighestSalary
-- FROM Employee
-- WHERE Salary < (SELECT max(Salary) FROM Employee);