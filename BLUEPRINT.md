# Job Simulator Blueprint

## Goal
- Play as a cashier at any store
- Take orders, confirm order, calculate price
- give change

### Stores
- Holds menu and item prices
- Calculates order

### Register
- Contains bills and coin values
- Calculate change to return
- check if change is correct

## Classes
- pokeBowl
- registerSys

## Data
- Menu: hashmap
- Coins/Bills: const values
- Customer queries: BST

## Game Flow

1. Birth, given 3 stores to work at
2. Start taking orders
3. Restate order to confirm correctness (a receipt)
4. Store calculates price
5. Register presents change due
6. User inputs correct coins/bills
7. Register checks if correct
8. Display success / error message
    - success = happy points
    - error = happy deductions
9. Order complete
    - Depending on happy points = tips



## Future
- Focus on cashiering system first before moving onto bigger ideas
- Track earnings
- Manager position
    - have all store funds
    - add decorative items to boost store perks
    - hire employees
    - responsibly stock items and make sure items aren't out of stock
    - purchase licenses
- Kitchen postion
    - work on the food
- Premium customers
- Choices: quit job, clock out, clock in, go home, shop
- different customer dialogues