/* Copyright (c) 2017-2018, Linaro Limited
 * Copyright (c) 2020, Marvell
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#include "ipsec.h"

#include "test_vectors.h"

static void test_in_ipv4_ah_sha256(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_sha256_tun_ipv4(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, true, 123, &tunnel,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_tun_ipv4_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_sha256_tun_ipv6(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, true, 123, &tunnel,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_tun_ipv6_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_sha256_tun_ipv4_notun(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_tun_ipv4_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  /* It is L4_TYPE_IPV4 */
			  .l4_type = _ODP_PROTO_L4_TYPE_UNDEF,
			  .pkt_res = &pkt_ipv4_icmp_0_ipip },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_null_sha256(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_aes_cbc_null(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_AES_CBC, &key_a5_128,
			    ODP_AUTH_ALG_NULL, NULL,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_aes_cbc_null_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_aes_cbc_sha1(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_AES_CBC, &key_a5_128,
			    ODP_AUTH_ALG_SHA1_HMAC, &key_5a_160,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_aes_cbc_sha1_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_aes_cbc_sha256(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_AES_CBC, &key_a5_128,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_aes_cbc_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_aes_cbc_sha384(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_AES_CBC, &key_a5_128,
			    ODP_AUTH_ALG_SHA384_HMAC, &key_5a_384,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_aes_cbc_sha384_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_aes_cbc_sha512(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_AES_CBC, &key_a5_128,
			    ODP_AUTH_ALG_SHA512_HMAC, &key_5a_512,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_aes_cbc_sha512_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_aes_ctr_null(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_AES_CTR, &key_a5_128,
			    ODP_AUTH_ALG_NULL, NULL,
			    &key_mcgrew_gcm_salt_3, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_aes_ctr_null_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_sha256_lookup(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1,
		.flags = {
			.lookup = 1,
		},
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_null_sha256_lookup(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1,
		.flags = {
			.lookup = 1,
		},
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_null_sha256_tun_ipv4(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 123, &tunnel,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_tun_ipv4_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_null_sha256_tun_ipv6(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 123, &tunnel,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_tun_ipv6_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_udp_null_sha256(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);
	param.opt.udp_encap = 1;

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_udp_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_udp_null_sha256_lookup(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);
	param.opt.udp_encap = 1;

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_udp_null_sha256_1,
		.flags = {
			.lookup = 1,
		},
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_sha256_noreplay(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);
	param.inbound.antireplay_ws = 0;

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_test_part test_1235 = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1235,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);
	ipsec_check_in_one(&test, sa);
	ipsec_check_in_one(&test_1235, sa);
	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_sha256_replay(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;
	ipsec_test_part test_repl;

	memset(&test_repl, 0, sizeof(ipsec_test_part));

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);
	param.inbound.antireplay_ws = 32;

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	test_repl.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1;
	test_repl.num_pkt = 1;
	test_repl.out[0].status.error.antireplay = 1;

	ipsec_test_part test_1235 = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1235,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);
	ipsec_check_in_one(&test_repl, sa);
	ipsec_check_in_one(&test_1235, sa);
	ipsec_check_in_one(&test_repl, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_null_sha256_noreplay(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);
	param.inbound.antireplay_ws = 0;

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_test_part test_1235 = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1235,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);
	ipsec_check_in_one(&test, sa);
	ipsec_check_in_one(&test_1235, sa);
	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_null_sha256_replay(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;
	ipsec_test_part test_repl;

	memset(&test_repl, 0, sizeof(ipsec_test_part));

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);
	param.inbound.antireplay_ws = 32;

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	test_repl.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1;
	test_repl.num_pkt = 1;
	test_repl.out[0].status.error.antireplay = 1;

	ipsec_test_part test_1235 = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1235,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);
	ipsec_check_in_one(&test_repl, sa);
	ipsec_check_in_one(&test_1235, sa);
	ipsec_check_in_one(&test_repl, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_esp_pkt(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;
	ipsec_test_part test;

	memset(&test, 0, sizeof(ipsec_test_part));

	/* This test will not work properly inbound inline mode.
	 * test_in_ipv4_ah_esp_pkt_lookup will be used instead. */
	if (suite_context.inbound_op_mode == ODP_IPSEC_OP_MODE_INLINE)
		return;

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	test.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1;
	test.num_pkt = 1;
	test.out[0].status.error.proto = 1;

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_ah_pkt(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;
	ipsec_test_part test;

	memset(&test, 0, sizeof(ipsec_test_part));

	/* This test will not work properly inbound inline mode.
	 * test_in_ipv4_esp_ah_pkt_lookup will be used instead. */
	if (suite_context.inbound_op_mode == ODP_IPSEC_OP_MODE_INLINE)
		return;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	test.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1;
	test.num_pkt = 1;
	test.out[0].status.error.proto = 1;

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_esp_pkt_lookup(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;
	ipsec_test_part test;

	memset(&test, 0, sizeof(ipsec_test_part));

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	test.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1;
	test.flags.lookup = 1;
	test.num_pkt = 1;
	test.out[0].status.error.sa_lookup = 1;

	ipsec_check_in_one(&test, ODP_IPSEC_SA_INVALID);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_ah_pkt_lookup(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;
	ipsec_test_part test;

	memset(&test, 0, sizeof(ipsec_test_part));

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	test.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1;
	test.flags.lookup = 1;
	test.num_pkt = 1;
	test.out[0].status.error.sa_lookup = 1;

	ipsec_check_in_one(&test, ODP_IPSEC_SA_INVALID);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_sha256_bad1(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;
	ipsec_test_part test;

	memset(&test, 0, sizeof(ipsec_test_part));

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	test.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1_bad1;
	test.num_pkt = 1;
	test.out[0].status.error.auth = 1;

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_sha256_bad2(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;
	ipsec_test_part test;

	memset(&test, 0, sizeof(ipsec_test_part));

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	test.pkt_in = &pkt_ipv4_icmp_0_ah_sha256_1_bad2;
	test.num_pkt = 1;
	test.out[0].status.error.auth = 1;

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_null_sha256_bad1(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;
	ipsec_test_part test;

	memset(&test, 0, sizeof(ipsec_test_part));

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	test.pkt_in = &pkt_ipv4_icmp_0_esp_null_sha256_1_bad1;
	test.num_pkt = 1;
	test.out[0].status.error.auth = 1;

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_rfc3602_5_esp(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 0x4321, NULL,
			    ODP_CIPHER_ALG_AES_CBC, &key_rfc3602,
			    ODP_AUTH_ALG_NULL, NULL,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_rfc3602_5_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_rfc3602_5 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_rfc3602_6_esp(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 0x4321, NULL,
			    ODP_CIPHER_ALG_AES_CBC, &key_rfc3602,
			    ODP_AUTH_ALG_NULL, NULL,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_rfc3602_6_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_rfc3602_6 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_rfc3602_7_esp(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 0x8765, &tunnel,
			    ODP_CIPHER_ALG_AES_CBC, &key_rfc3602_2,
			    ODP_AUTH_ALG_NULL, NULL,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_rfc3602_7_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_rfc3602_7 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_rfc3602_8_esp(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 0x8765, &tunnel,
			    ODP_CIPHER_ALG_AES_CBC, &key_rfc3602_2,
			    ODP_AUTH_ALG_NULL, NULL,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_rfc3602_8_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_rfc3602_8 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_mcgrew_gcm_2_esp(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 0xa5f8, &tunnel,
			    ODP_CIPHER_ALG_AES_GCM, &key_mcgrew_gcm_2,
			    ODP_AUTH_ALG_AES_GCM, NULL,
			    &key_mcgrew_gcm_salt_2, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_mcgrew_gcm_test_2_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_UDP,
			  .pkt_res = &pkt_mcgrew_gcm_test_2},
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_mcgrew_gcm_3_esp(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 0x4a2cbfe3, &tunnel,
			    ODP_CIPHER_ALG_AES_GCM, &key_mcgrew_gcm_3,
			    ODP_AUTH_ALG_AES_GCM, NULL,
			    &key_mcgrew_gcm_salt_3, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_mcgrew_gcm_test_3_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = _ODP_PROTO_L4_TYPE_UNDEF,
			  .pkt_res = &pkt_mcgrew_gcm_test_3},
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_mcgrew_gcm_4_esp(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 0x00000000, &tunnel,
			    ODP_CIPHER_ALG_AES_GCM, &key_mcgrew_gcm_4,
			    ODP_AUTH_ALG_AES_GCM, NULL,
			    &key_mcgrew_gcm_salt_4, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_mcgrew_gcm_test_4_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_mcgrew_gcm_test_4},
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_mcgrew_gcm_12_esp(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	/* This test will not work properly inbound inline mode.
	 * Packet might be dropped and we will not check for that. */
	if (suite_context.inbound_op_mode == ODP_IPSEC_OP_MODE_INLINE)
		return;

	ipsec_sa_param_fill(&param,
			    true, false, 0x335467ae, &tunnel,
			    ODP_CIPHER_ALG_AES_GCM, &key_mcgrew_gcm_12,
			    ODP_AUTH_ALG_AES_GCM, NULL,
			    &key_mcgrew_gcm_salt_12, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_mcgrew_gcm_test_12_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_NONE,
			  .l4_type = _ODP_PROTO_L4_TYPE_UNDEF,
			  .pkt_res = &pkt_mcgrew_gcm_test_12},
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_mcgrew_gcm_12_esp_notun(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 0x335467ae, NULL,
			    ODP_CIPHER_ALG_AES_GCM, &key_mcgrew_gcm_12,
			    ODP_AUTH_ALG_AES_GCM, NULL,
			    &key_mcgrew_gcm_salt_12, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_mcgrew_gcm_test_12_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_NO_NEXT,
			  .pkt_res = &pkt_mcgrew_gcm_test_12_notun },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_mcgrew_gcm_15_esp(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 0x00004321, &tunnel,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_AES_GMAC, &key_mcgrew_gcm_15,
			    NULL, &key_mcgrew_gcm_salt_15);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_mcgrew_gcm_test_15_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_mcgrew_gcm_test_15},
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_rfc7634_chacha(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 0x01020304, &tunnel,
			    ODP_CIPHER_ALG_CHACHA20_POLY1305, &key_rfc7634,
			    ODP_AUTH_ALG_CHACHA20_POLY1305, NULL,
			    &key_rfc7634_salt, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_rfc7634_esp,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_rfc7634},
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_ah_aes_gmac_128(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_AES_GMAC, &key_a5_128,
			    NULL, &key_mcgrew_gcm_salt_2);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_ah_aes_gmac_128_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv4_esp_null_aes_gmac_128(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_AES_GMAC, &key_a5_128,
			    NULL, &key_mcgrew_gcm_salt_2);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv4_icmp_0_esp_null_aes_gmac_128_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV4,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV4,
			  .pkt_res = &pkt_ipv4_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv6_ah_sha256(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, true, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv6_icmp_0_ah_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV6,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV6,
			  .pkt_res = &pkt_ipv6_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv6_ah_sha256_tun_ipv4(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, true, 123, &tunnel,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv6_icmp_0_ah_tun_ipv4_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV6,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV6,
			  .pkt_res = &pkt_ipv6_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv6_ah_sha256_tun_ipv6(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, true, 123, &tunnel,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv6_icmp_0_ah_tun_ipv6_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV6,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV6,
			  .pkt_res = &pkt_ipv6_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv6_esp_null_sha256(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv6_icmp_0_esp_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV6,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV6,
			  .pkt_res = &pkt_ipv6_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv6_esp_null_sha256_tun_ipv4(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 123, &tunnel,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv6_icmp_0_esp_tun_ipv4_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV6,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV6,
			  .pkt_res = &pkt_ipv6_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv6_esp_null_sha256_tun_ipv6(void)
{
	odp_ipsec_tunnel_param_t tunnel;
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	memset(&tunnel, 0, sizeof(odp_ipsec_tunnel_param_t));

	ipsec_sa_param_fill(&param,
			    true, false, 123, &tunnel,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv6_icmp_0_esp_tun_ipv6_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV6,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV6,
			  .pkt_res = &pkt_ipv6_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv6_esp_udp_null_sha256(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);
	param.opt.udp_encap = 1;

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv6_icmp_0_esp_udp_null_sha256_1,
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV6,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV6,
			  .pkt_res = &pkt_ipv6_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_in_ipv6_esp_udp_null_sha256_lookup(void)
{
	odp_ipsec_sa_param_t param;
	odp_ipsec_sa_t sa;

	ipsec_sa_param_fill(&param,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_NULL, NULL,
			    ODP_AUTH_ALG_SHA256_HMAC, &key_5a_256,
			    NULL, NULL);
	param.opt.udp_encap = 1;

	sa = odp_ipsec_sa_create(&param);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, sa);

	ipsec_test_part test = {
		.pkt_in = &pkt_ipv6_icmp_0_esp_udp_null_sha256_1,
		.flags = {
			.lookup = 1,
		},
		.num_pkt = 1,
		.out = {
			{ .status.warn.all = 0,
			  .status.error.all = 0,
			  .l3_type = ODP_PROTO_L3_TYPE_IPV6,
			  .l4_type = ODP_PROTO_L4_TYPE_ICMPV6,
			  .pkt_res = &pkt_ipv6_icmp_0 },
		},
	};

	ipsec_check_in_one(&test, sa);

	ipsec_sa_destroy(sa);
}

static void test_ipsec_print(void)
{
	odp_ipsec_print();
}

static void test_ipsec_sa_print(void)
{
	odp_ipsec_sa_param_t param_in;
	odp_ipsec_sa_t in_sa;

	ipsec_sa_param_fill(&param_in,
			    true, false, 123, NULL,
			    ODP_CIPHER_ALG_AES_CBC, &key_a5_128,
			    ODP_AUTH_ALG_SHA1_HMAC, &key_5a_160,
			    NULL, NULL);

	in_sa = odp_ipsec_sa_create(&param_in);

	CU_ASSERT_NOT_EQUAL_FATAL(ODP_IPSEC_SA_INVALID, in_sa);

	odp_ipsec_sa_print(in_sa);

	ipsec_sa_destroy(in_sa);
}

static void ipsec_test_capability(void)
{
	odp_ipsec_capability_t capa;

	CU_ASSERT(odp_ipsec_capability(&capa) == 0);
}

odp_testinfo_t ipsec_in_suite[] = {
	ODP_TEST_INFO(ipsec_test_capability),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_rfc3602_5_esp,
				  ipsec_check_esp_aes_cbc_128_null),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_rfc3602_6_esp,
				  ipsec_check_esp_aes_cbc_128_null),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_rfc3602_7_esp,
				  ipsec_check_esp_aes_cbc_128_null),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_rfc3602_8_esp,
				  ipsec_check_esp_aes_cbc_128_null),
	/* test 1, 5, 6, 8 -- 11 -- ESN */
	/* test 7 -- invalid, plaintext packet includes trl into IP length */
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_mcgrew_gcm_2_esp,
				  ipsec_check_esp_aes_gcm_128),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_mcgrew_gcm_3_esp,
				  ipsec_check_esp_aes_gcm_256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_mcgrew_gcm_4_esp,
				  ipsec_check_esp_aes_gcm_128),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_mcgrew_gcm_12_esp,
				  ipsec_check_esp_aes_gcm_128),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_mcgrew_gcm_12_esp_notun,
				  ipsec_check_esp_aes_gcm_128),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_mcgrew_gcm_15_esp,
				  ipsec_check_esp_null_aes_gmac_128),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_rfc7634_chacha,
				  ipsec_check_esp_chacha20_poly1305),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_sha256,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_sha256_tun_ipv4,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_sha256_tun_ipv6,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_sha256_tun_ipv4_notun,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_null_sha256,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_aes_cbc_null,
				  ipsec_check_esp_aes_cbc_128_null),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_aes_cbc_sha1,
				  ipsec_check_esp_aes_cbc_128_sha1),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_aes_cbc_sha256,
				  ipsec_check_esp_aes_cbc_128_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_aes_cbc_sha384,
				  ipsec_check_esp_aes_cbc_128_sha384),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_aes_cbc_sha512,
				  ipsec_check_esp_aes_cbc_128_sha512),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_aes_ctr_null,
				  ipsec_check_esp_aes_ctr_128_null),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_sha256_lookup,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_null_sha256_lookup,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_null_sha256_tun_ipv4,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_null_sha256_tun_ipv6,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_udp_null_sha256,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_udp_null_sha256_lookup,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_sha256_noreplay,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_sha256_replay,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_null_sha256_noreplay,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_null_sha256_replay,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_esp_pkt,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_ah_pkt,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_esp_pkt_lookup,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_ah_pkt_lookup,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_sha256_bad1,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_sha256_bad2,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_null_sha256_bad1,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_ah_aes_gmac_128,
				  ipsec_check_ah_aes_gmac_128),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv4_esp_null_aes_gmac_128,
				  ipsec_check_esp_null_aes_gmac_128),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv6_ah_sha256,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv6_ah_sha256_tun_ipv4,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv6_ah_sha256_tun_ipv6,
				  ipsec_check_ah_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv6_esp_null_sha256,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv6_esp_null_sha256_tun_ipv4,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv6_esp_null_sha256_tun_ipv6,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv6_esp_udp_null_sha256,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO_CONDITIONAL(test_in_ipv6_esp_udp_null_sha256_lookup,
				  ipsec_check_esp_null_sha256),
	ODP_TEST_INFO(test_ipsec_print),
	ODP_TEST_INFO_CONDITIONAL(test_ipsec_sa_print,
				  ipsec_check_esp_aes_cbc_128_sha1),
	ODP_TEST_INFO_NULL,
};
