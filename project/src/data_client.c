#include "data_client.h"
#include "output.h"

void write_clients(FILE *f, Data Client) {
    print_info_client();
    while (scanf("%d%19s%19s%29s%14s%lf%lf%lf", &Client.number, Client.name, Client.surname, Client.address,
                 Client.tel_number, &Client.indebtedness, &Client.credit_limit, &Client.cash_payments) == 8) {
        print_to_file(f, Client);
        print_info_client();
    }
}

