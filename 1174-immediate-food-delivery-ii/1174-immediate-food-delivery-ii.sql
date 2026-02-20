# Write your MySQL query statement below
with cte_table as
(
select 
    *
from 
(
    select
        *,
        row_number() over (partition by customer_id order by order_date) as dup
    from    
        Delivery
) as newtt
where dup=1
)
select 
    round(
        sum(
            case 
                when order_date=customer_pref_delivery_date then 1
                else 0
            End
        )*100/count(*),2
    ) as 'immediate_percentage'
from    
(
select 
    *
    -- order_date =customer_pref_delivery_date as comp
from 
    cte_table
) as tt
