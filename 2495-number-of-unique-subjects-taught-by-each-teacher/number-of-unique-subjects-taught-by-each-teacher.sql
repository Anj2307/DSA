# Write your MySQL query statement below
select teacher_id ,count(distinct subject_id) as cnt 
from Teacher
where (teacher_id, subject_id)in (select distinct teacher_id, subject_id from Teacher)
group by teacher_id;