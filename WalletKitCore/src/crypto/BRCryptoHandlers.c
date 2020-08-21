//
//  BRCryptoHandlers.c
//  Core
//
//  Created by Ed Gamble on 4/24/20.
//  Copyright © 2019 Breadwallet AG. All rights reserved.
//
//  See the LICENSE file at the project root for license information.
//  See the CONTRIBUTORS file at the project root for a list of contributors.
//
#include "BRCryptoHandlersP.h"

// The specific handlers for each supported currency
#include "handlers/BRCryptoHandlersExport.h"

// Must be ordered by BRCryptoBlockChainType enumeration values.
static BRCryptoHandlers handlers[NUMBER_OF_NETWORK_TYPES] = {
    {
        CRYPTO_NETWORK_TYPE_BTC,
        &cryptoNetworkHandlersBTC,
        &cryptoAddressHandlersBTC,
        &cryptoTransferHandlersBTC,
        &cryptoWalletHandlersBTC,
        &cryptoWalletSweeperHandlersBTC,
        &cryptoPaymentProtocolHandlersBTC,
        &cryptoWalletManagerHandlersBTC
    },

    {
        CRYPTO_NETWORK_TYPE_BCH,
        &cryptoNetworkHandlersBCH,
        &cryptoAddressHandlersBCH,
        &cryptoTransferHandlersBCH,
        &cryptoWalletHandlersBCH,
        &cryptoWalletSweeperHandlersBCH,
        &cryptoPaymentProtocolHandlersBTC,
        &cryptoWalletManagerHandlersBCH
    },

    {
        CRYPTO_NETWORK_TYPE_BSV,
        &cryptoNetworkHandlersBSV,
        &cryptoAddressHandlersBSV,
        &cryptoTransferHandlersBSV,
        &cryptoWalletHandlersBSV,
        &cryptoWalletSweeperHandlersBSV,
        &cryptoPaymentProtocolHandlersBTC,
        &cryptoWalletManagerHandlersBSV
    },

    {
        CRYPTO_NETWORK_TYPE_ETH,
        &cryptoNetworkHandlersETH,
        &cryptoAddressHandlersETH,
        &cryptoTransferHandlersETH,
        &cryptoWalletHandlersETH,
        NULL,//BRCryptoWalletSweeperHandlers not supported
        NULL,//BRCryptoPaymentProtocolHandlers not supported
        &cryptoWalletManagerHandlersETH
    },

    {
        CRYPTO_NETWORK_TYPE_XRP,
        &cryptoNetworkHandlersXRP,
        &cryptoAddressHandlersXRP,
        &cryptoTransferHandlersXRP,
        &cryptoWalletHandlersXRP,
        NULL,//BRCryptoWalletSweeperHandlers not supported
        NULL,//BRCryptoPaymentProtocolHandlers not supported
        &cryptoWalletManagerHandlersXRP
    },

    {
        CRYPTO_NETWORK_TYPE_HBAR,
        &cryptoNetworkHandlersHBAR,
        &cryptoAddressHandlersHBAR,
        &cryptoTransferHandlersHBAR,
        &cryptoWalletHandlersHBAR,
        NULL,//BRCryptoWalletSweeperHandlers not supported
        NULL,//BRCryptoPaymentProtocolHandlers not supported
        &cryptoWalletManagerHandlersHBAR
    },
};

extern const BRCryptoHandlers *
cryptoHandlersLookup (BRCryptoBlockChainType type) {
    assert (type < NUMBER_OF_NETWORK_TYPES);
    return &handlers[type];
}