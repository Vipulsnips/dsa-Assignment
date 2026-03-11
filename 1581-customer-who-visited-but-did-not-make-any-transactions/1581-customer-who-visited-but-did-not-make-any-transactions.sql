select 
    distinct(customer_id),count(customer_id) over(partition by customer_id) as count_no_trans 
from
(
select
    customer_id,transaction_id,V.visit_id,amount
from
    Visits as v
left join
    Transactions as t
on v.visit_id=t.visit_id
) as newt
where 
    transaction_id is null;