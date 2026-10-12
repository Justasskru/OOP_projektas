# OOP_projektas

## Paleidimas

```bash
cmake -S . -B build
cmake --build build
./build/shop
```

## SOLID / OOP lentelė

| Principas | Failas / klasė | Kodėl taip |
|---|---|---|
| Inkapsuliacija | `src/orders/Order.h` (`private items_`) | Išorė negali tiesiogiai keisti užsakymo elementų sąrašo. |
| Paveldėjimas | `PhysicalProduct : Product`, `DigitalProduct : Product` | Bendri produkto duomenys ir elgesio sutartis laikomi bazinėje klasėje. |
| Polimorfizmas | `OrderService::checkout(... IPaymentMethod&)` | Tas pats `pay()` kvietimas veikia skirtingiems mokėjimo būdams. |
| Abstrakcija | `Product`, `IPaymentMethod`, `IDiscountStrategy`, `IOrderRepository` | Aukštesnio lygio logika remiasi sutartimis, ne detalėmis. |
| SRP | `Order`, `OrderPriceCalculator`, `ReceiptPrinter` | Užsakymas saugo duomenis, skaičiuoklė skaičiuoja, spausdintuvas spausdina. |
| OCP | `IDiscountStrategy` + realizacijos | Nauja nuolaida pridedama nauja klase be esamos logikos keitimo. |
| LSP | `DigitalProduct`/`PhysicalProduct` naudojami kaip `Product` | Abi realizacijos saugiai naudojamos per bazinę klasę. |
| ISP | `IShippable` realizuoja tik `PhysicalProduct` | Skaitmeninė prekė neturi pristatymo metodų, kurių nenaudoja. |
| DIP | `OrderService(IOrderRepository&, ...)` | Saugojimo įgyvendinimą galima keisti nekeičiant `OrderService`. |

## Demonstracija

- 3 prekės (2 fizinės, 1 skaitmeninė).
- Nuolaidos: be nuolaidos, 10 %, „pirk 3 mokėk 2“.
- Mokėjimai: kortelė, PayPal, grynieji.
- Repozitorijos: failas (`orders.csv`) arba atmintis.
