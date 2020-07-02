/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2019-2020 Broadcom
 * All rights reserved.
 */

#ifndef _TF_IDENTIFIER_H_
#define _TF_IDENTIFIER_H_

#include "tf_core.h"

/**
 * The Identifier module provides processing of Identifiers.
 */

struct tf_ident_cfg {
	/**
	 * Number of identifier types in each of the configuration
	 * arrays
	 */
	uint16_t num_elements;

	/**
	 * TCAM configuration array
	 */
	struct tf_rm_element_cfg *ident_cfg[TF_DIR_MAX];
};

/**
 * Identifier allcoation parameter definition
 */
struct tf_ident_alloc_parms {
	/**
	 * [in] receive or transmit direction
	 */
	enum tf_dir dir;
	/**
	 * [in] Identifier type
	 */
	enum tf_identifier_type ident_type;
	/**
	 * [out] Identifier allocated
	 */
	uint16_t id;
};

/**
 * Identifier free parameter definition
 */
struct tf_ident_free_parms {
	/**
	 * [in]	 receive or transmit direction
	 */
	enum tf_dir dir;
	/**
	 * [in] Identifier type
	 */
	enum tf_identifier_type ident_type;
	/**
	 * [in] ID to free
	 */
	uint16_t id;
};

/**
 * @page ident Identity Management
 *
 * @ref tf_ident_bind
 *
 * @ref tf_ident_unbind
 *
 * @ref tf_ident_alloc
 *
 * @ref tf_ident_free
 */

/**
 * Initializes the Identifier module with the requested DBs. Must be
 * invoked as the first thing before any of the access functions.
 *
 * [in] tfp
 *   Pointer to TF handle, used for HCAPI communication
 *
 * [in] parms
 *   Pointer to parameters
 *
 * Returns
 *   - (0) if successful.
 *   - (-EINVAL) on failure.
 */
int tf_ident_bind(struct tf *tfp,
		  struct tf_ident_cfg *parms);

/**
 * Cleans up the private DBs and releases all the data.
 *
 * [in] tfp
 *   Pointer to TF handle, used for HCAPI communication
 *
 * [in] parms
 *   Pointer to parameters
 *
 * Returns
 *   - (0) if successful.
 *   - (-EINVAL) on failure.
 */
int tf_ident_unbind(struct tf *tfp);

/**
 * Allocates a single identifier type.
 *
 * [in] tfp
 *   Pointer to TF handle, used for HCAPI communication
 *
 * [in] parms
 *   Pointer to parameters
 *
 * Returns
 *   - (0) if successful.
 *   - (-EINVAL) on failure.
 */
int tf_ident_alloc(struct tf *tfp,
		   struct tf_ident_alloc_parms *parms);

/**
 * Free's a single identifier type.
 *
 * [in] tfp
 *   Pointer to TF handle, used for HCAPI communication
 *
 * [in] parms
 *   Pointer to parameters
 *
 * Returns
 *   - (0) if successful.
 *   - (-EINVAL) on failure.
 */
int tf_ident_free(struct tf *tfp,
		  struct tf_ident_free_parms *parms);

#endif /* _TF_IDENTIFIER_H_ */
