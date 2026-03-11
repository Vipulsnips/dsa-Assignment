# Write your MySQL query statement below
select id
from
(
select 
    w.id,w.recordDate,ww.recordDate as newd,w.temperature,ww.temperature as newt
from    
    Weather as w
join 
    Weather as ww
on ww.recordDate=subdate(w.recordDate,1)
) as newt
where
     temperature>newt