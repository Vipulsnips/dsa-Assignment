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
) as newt
where
    newd=subdate(recordDate,1) && temperature>newt