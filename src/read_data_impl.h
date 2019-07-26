/*
 * Copyright (c) 2019, Christopher C. Hulbert
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define READ_TYPE_DOUBLE_DATA CAT(READ_TYPED_FUNC1, Double)
#define READ_TYPE_SINGLE_DATA CAT(READ_TYPED_FUNC1, Single)
#define READ_TYPE_INT32_DATA CAT(READ_TYPED_FUNC1, Int32)
#define READ_TYPE_UINT32_DATA CAT(READ_TYPED_FUNC1, UInt32)
#define READ_TYPE_INT16_DATA CAT(READ_TYPED_FUNC1, Int16)
#define READ_TYPE_UINT16_DATA CAT(READ_TYPED_FUNC1, UInt16)
#define READ_TYPE_INT8_DATA CAT(READ_TYPED_FUNC1, Int8)
#define READ_TYPE_UINT8_DATA CAT(READ_TYPED_FUNC1, UInt8)
#ifdef HAVE_MAT_INT64_T
#define READ_TYPE_INT64_DATA CAT(READ_TYPED_FUNC1, Int64)
#endif /* HAVE_MAT_INT64_T */
#ifdef HAVE_MAT_UINT64_T
#define READ_TYPE_UINT64_DATA CAT(READ_TYPED_FUNC1, UInt64)
#endif /* HAVE_MAT_UINT64_T */

static size_t
READ_TYPE_DOUBLE_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_DOUBLE
    bytesread += fread(data, sizeof(double), len, (FILE*)mat->fp);
    if ( mat->byteswap ) {
        size_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_doubleSwap(data + i);
        }
    }
#else
    size_t i;
    const size_t data_size = sizeof(double);
    double v[READ_BLOCK_SIZE/sizeof(double)];
    READ_DATA(READ_TYPE, Mat_doubleSwap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_SINGLE_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_SINGLE
    bytesread += fread(data, sizeof(float), len, (FILE*)mat->fp);
    if ( mat->byteswap ) {
        size_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_floatSwap(data + i);
        }
    }
#else
    size_t i;
    const size_t data_size = sizeof(float);
    float v[READ_BLOCK_SIZE/sizeof(float)];
    READ_DATA(READ_TYPE, Mat_floatSwap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_INT32_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_INT32
    bytesread += fread(data, sizeof(mat_int32_t), len, (FILE*)mat->fp);
    if ( mat->byteswap ) {
        size_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_int32Swap(data + i);
        }
    }
#else
    size_t i;
    const size_t data_size = sizeof(mat_int32_t);
    mat_int32_t v[READ_BLOCK_SIZE/sizeof(mat_int32_t)];
    READ_DATA(READ_TYPE, Mat_int32Swap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_UINT32_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_UINT32
    bytesread += fread(data, sizeof(mat_uint32_t), len, (FILE*)mat->fp);
    if ( mat->byteswap ) {
        size_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_uint32Swap(data + i);
        }
    }
#else
    size_t i;
    const size_t data_size = sizeof(mat_uint32_t);
    mat_uint32_t v[READ_BLOCK_SIZE/sizeof(mat_uint32_t)];
    READ_DATA(READ_TYPE, Mat_uint32Swap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_INT16_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_INT16
    bytesread += fread(data, sizeof(mat_int16_t), len, (FILE*)mat->fp);
    if ( mat->byteswap ) {
        size_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_int16Swap(data + i);
        }
    }
#else
    size_t i;
    const size_t data_size = sizeof(mat_int16_t);
    mat_int16_t v[READ_BLOCK_SIZE/sizeof(mat_int16_t)];
    READ_DATA(READ_TYPE, Mat_int16Swap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_UINT16_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_UINT16
    bytesread += fread(data, sizeof(mat_uint16_t), len, (FILE*)mat->fp);
    if ( mat->byteswap ) {
        size_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_uint16Swap(data + i);
        }
    }
#else
    size_t i;
    const size_t data_size = sizeof(mat_uint16_t);
    mat_uint16_t v[READ_BLOCK_SIZE/sizeof(mat_uint16_t)];
    READ_DATA(READ_TYPE, Mat_uint16Swap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_INT8_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_INT8
    bytesread += fread(data, sizeof(mat_int8_t), len, (FILE*)mat->fp);
#else
    size_t i;
    const size_t data_size = sizeof(mat_int8_t);
    mat_int8_t v[READ_BLOCK_SIZE/sizeof(mat_int8_t)];
    READ_DATA_NOSWAP(READ_TYPE);
#endif
    return bytesread;
}

static size_t
READ_TYPE_UINT8_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_UINT8
    bytesread += fread(data, sizeof(mat_uint8_t), len, (FILE*)mat->fp);
#else
    size_t i;
    const size_t data_size = sizeof(mat_uint8_t);
    mat_uint8_t v[READ_BLOCK_SIZE/sizeof(mat_uint8_t)];
    READ_DATA_NOSWAP(READ_TYPE);
#endif
    return bytesread;
}

#ifdef HAVE_MAT_INT64_T
static size_t
READ_TYPE_INT64_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_INT64
    bytesread += fread(data, sizeof(mat_int64_t), len, (FILE*)mat->fp);
    if ( mat->byteswap ) {
        size_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_int64Swap(data + i);
        }
    }
#else
    size_t i;
    const size_t data_size = sizeof(mat_int64_t);
    mat_int64_t v[READ_BLOCK_SIZE/sizeof(mat_int64_t)];
    READ_DATA(READ_TYPE, Mat_int64Swap);
#endif
    return bytesread;
}
#endif /* HAVE_MAT_INT64_T */

#ifdef HAVE_MAT_UINT64_T
static size_t
READ_TYPE_UINT64_DATA(mat_t *mat, READ_TYPE *data, size_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_UINT64
    bytesread += fread(data, sizeof(mat_uint64_t), len, (FILE*)mat->fp);
    if ( mat->byteswap ) {
        size_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_uint64Swap(data + i);
        }
    }
#else
    size_t i;
    const size_t data_size = sizeof(mat_uint64_t);
    mat_uint64_t v[READ_BLOCK_SIZE/sizeof(mat_uint64_t)];
    READ_DATA(READ_TYPE, Mat_uint64Swap);
#endif
    return bytesread;
}
#endif /* HAVE_MAT_UINT64_T */


/** @brief Reads data of type @c data_type into a READ_TYPE type
 *
 * Reads from the MAT file @c len elements of data type @c data_type storing
 * them as READ_TYPE's in @c data.
 * @ingroup mat_internal
 * @param mat MAT file pointer
 * @param data Pointer to store the output values (len*sizeof(READ_TYPE))
 * @param data_type one of the @c matio_types enumerations which is the source
 *                  data type in the file
 * @param len Number of elements of type @c data_type to read from the file
 * @retval Number of bytes read from the file
 */
int
READ_TYPED_FUNC1(mat_t *mat, READ_TYPE *data, enum matio_types data_type, size_t len)
{
    size_t bytesread = 0;

    if ( mat == NULL || data == NULL || mat->fp == NULL )
        return 0;

    switch ( data_type ) {
        case MAT_T_DOUBLE:
            bytesread = READ_TYPE_DOUBLE_DATA(mat, data, len);
            break;
        case MAT_T_SINGLE:
            bytesread = READ_TYPE_SINGLE_DATA(mat, data, len);
            break;
#ifdef HAVE_MAT_INT64_T
        case MAT_T_INT64:
            bytesread = READ_TYPE_INT64_DATA(mat, data, len);
            break;
#endif /* HAVE_MAT_UINT64_T */
#ifdef HAVE_MAT_UINT64_T
        case MAT_T_UINT64:
            bytesread = READ_TYPE_UINT64_DATA(mat, data, len);
            break;
#endif /* HAVE_MAT_UINT64_T */
        case MAT_T_INT32:
            bytesread = READ_TYPE_INT32_DATA(mat, data, len);
            break;
        case MAT_T_UINT32:
            bytesread = READ_TYPE_UINT32_DATA(mat, data, len);
            break;
        case MAT_T_INT16:
            bytesread = READ_TYPE_INT16_DATA(mat, data, len);
            break;
        case MAT_T_UINT16:
            bytesread = READ_TYPE_UINT16_DATA(mat, data, len);
            break;
        case MAT_T_INT8:
            bytesread = READ_TYPE_INT8_DATA(mat, data, len);
            break;
        case MAT_T_UINT8:
            bytesread = READ_TYPE_UINT8_DATA(mat, data, len);
            break;
        default:
            break;
    }
    bytesread *= Mat_SizeOf(data_type);
    return bytesread;
}

#undef READ_TYPE_DOUBLE_DATA
#undef READ_TYPE_SINGLE_DATA
#undef READ_TYPE_INT32_DATA
#undef READ_TYPE_UINT32_DATA
#undef READ_TYPE_INT16_DATA
#undef READ_TYPE_UINT16_DATA
#undef READ_TYPE_INT8_DATA
#undef READ_TYPE_UINT8_DATA
#ifdef HAVE_MAT_INT64_T
#undef READ_TYPE_INT64_DATA
#endif /* HAVE_MAT_INT64_T */
#ifdef HAVE_MAT_UINT64_T
#undef READ_TYPE_UINT64_DATA
#endif /* HAVE_MAT_UINT64_T */

#if defined(HAVE_ZLIB)

#define READ_TYPE_DOUBLE_DATA CAT(READ_TYPED_FUNC2, Double)
#define READ_TYPE_SINGLE_DATA CAT(READ_TYPED_FUNC2, Single)
#define READ_TYPE_INT32_DATA CAT(READ_TYPED_FUNC2, Int32)
#define READ_TYPE_UINT32_DATA CAT(READ_TYPED_FUNC2, UInt32)
#define READ_TYPE_INT16_DATA CAT(READ_TYPED_FUNC2, Int16)
#define READ_TYPE_UINT16_DATA CAT(READ_TYPED_FUNC2, UInt16)
#define READ_TYPE_INT8_DATA CAT(READ_TYPED_FUNC2, Int8)
#define READ_TYPE_UINT8_DATA CAT(READ_TYPED_FUNC2, UInt8)
#ifdef HAVE_MAT_INT64_T
#define READ_TYPE_INT64_DATA CAT(READ_TYPED_FUNC2, Int64)
#endif /* HAVE_MAT_INT64_T */
#ifdef HAVE_MAT_UINT64_T
#define READ_TYPE_UINT64_DATA CAT(READ_TYPED_FUNC2, UInt64)
#endif /* HAVE_MAT_UINT64_T */

static size_t
READ_TYPE_DOUBLE_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_DOUBLE
    bytesread = InflateData(mat, z, data, len*sizeof(double));
    if ( mat->byteswap ) {
        mat_uint32_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_doubleSwap(data + i);
        }
    }
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(double);
    double v[READ_BLOCK_SIZE/sizeof(double)];
    READ_COMPRESSED_DATA(READ_TYPE, Mat_doubleSwap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_SINGLE_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_SINGLE
    bytesread = InflateData(mat, z, data, len*sizeof(float));
    if ( mat->byteswap ) {
        mat_uint32_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_floatSwap(data + i);
        }
    }
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(float);
    float v[READ_BLOCK_SIZE/sizeof(float)];
    READ_COMPRESSED_DATA(READ_TYPE, Mat_floatSwap);
#endif
    return bytesread;
}

#ifdef HAVE_MAT_INT64_T
static size_t
READ_TYPE_INT64_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_INT64
    bytesread = InflateData(mat, z, data, len*sizeof(mat_int64_t));
    if ( mat->byteswap ) {
        mat_uint32_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_int64Swap(data + i);
        }
    }
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(mat_int64_t);
    mat_int64_t v[READ_BLOCK_SIZE/sizeof(mat_int64_t)];
    READ_COMPRESSED_DATA(READ_TYPE, Mat_int64Swap);
#endif
    return bytesread;
}
#endif /* HAVE_MAT_INT64_T */

#ifdef HAVE_MAT_UINT64_T
static size_t
READ_TYPE_UINT64_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_UINT64
    bytesread = InflateData(mat, z, data, len*sizeof(mat_uint64_t));
    if ( mat->byteswap ) {
        mat_uint32_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_uint64Swap(data + i);
        }
    }
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(mat_uint64_t);
    mat_uint64_t v[READ_BLOCK_SIZE/sizeof(mat_uint64_t)];
    READ_COMPRESSED_DATA(READ_TYPE, Mat_uint64Swap);
#endif
    return bytesread;
}
#endif /* HAVE_MAT_UINT64_T */

static size_t
READ_TYPE_INT32_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_INT32
    bytesread = InflateData(mat, z, data, len*sizeof(mat_int32_t));
    if ( mat->byteswap ) {
        mat_uint32_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_int32Swap(data + i);
        }
    }
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(mat_int32_t);
    mat_int32_t v[READ_BLOCK_SIZE/sizeof(mat_int32_t)];
    READ_COMPRESSED_DATA(READ_TYPE, Mat_int32Swap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_UINT32_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_UINT32
    bytesread = InflateData(mat, z, data, len*sizeof(mat_uint32_t));
    if ( mat->byteswap ) {
        mat_uint32_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_uint32Swap(data + i);
        }
    }
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(mat_uint32_t);
    mat_uint32_t v[READ_BLOCK_SIZE/sizeof(mat_uint32_t)];
    READ_COMPRESSED_DATA(READ_TYPE, Mat_uint32Swap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_INT16_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_INT16
    bytesread = InflateData(mat, z, data, len*sizeof(mat_int16_t));
    if ( mat->byteswap ) {
        mat_uint32_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_int16Swap(data + i);
        }
    }
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(mat_int16_t);
    mat_int16_t v[READ_BLOCK_SIZE/sizeof(mat_int16_t)];
    READ_COMPRESSED_DATA(READ_TYPE, Mat_int16Swap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_UINT16_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_UINT16
    bytesread = InflateData(mat, z, data, len*sizeof(mat_uint16_t));
    if ( mat->byteswap ) {
        mat_uint32_t i;
        for ( i = 0; i < len; i++ ) {
            (void)Mat_uint16Swap(data + i);
        }
    }
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(mat_uint16_t);
    mat_uint16_t v[READ_BLOCK_SIZE/sizeof(mat_uint16_t)];
    READ_COMPRESSED_DATA(READ_TYPE, Mat_uint16Swap);
#endif
    return bytesread;
}

static size_t
READ_TYPE_INT8_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_INT8
    bytesread = InflateData(mat, z, data, len*sizeof(mat_int8_t));
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(mat_int8_t);
    mat_int8_t v[READ_BLOCK_SIZE/sizeof(mat_int8_t)];
    READ_COMPRESSED_DATA_NOSWAP(READ_TYPE);
#endif
    return bytesread;
}

static size_t
READ_TYPE_UINT8_DATA(mat_t *mat, z_streamp z, READ_TYPE *data, mat_uint32_t len)
{
    size_t bytesread = 0;
#if READ_TYPE_TYPE == READ_TYPE_UINT8
    bytesread = InflateData(mat, z, data, len*sizeof(mat_uint8_t));
#else
    mat_uint32_t i;
    const size_t data_size = sizeof(mat_uint8_t);
    mat_uint8_t v[READ_BLOCK_SIZE/sizeof(mat_uint8_t)];
    READ_COMPRESSED_DATA_NOSWAP(READ_TYPE);
#endif
    return bytesread;
}

/** @brief Reads data of type @c data_type into a READ_TYPE type
 *
 * Reads from the MAT file @c len compressed elements of data type @c data_type
 * storing them as READ_TYPE's in @c data.
 * @ingroup mat_internal
 * @param mat MAT file pointer
 * @param z Pointer to the zlib stream for inflation
 * @param data Pointer to store the output values (len*sizeof(READ_TYPE))
 * @param data_type one of the @c matio_types enumerations which is the source
 *                  data type in the file
 * @param len Number of elements of type @c data_type to read from the file
 * @retval Number of bytes read from the file
 */
int
READ_TYPED_FUNC2(mat_t *mat, z_streamp z, READ_TYPE *data, enum matio_types data_type, int len)
{
    if ( mat == NULL || data == NULL || mat->fp == NULL )
        return 0;

    switch ( data_type ) {
        case MAT_T_DOUBLE:
            READ_TYPE_DOUBLE_DATA(mat, z, data, len);
            break;
        case MAT_T_SINGLE:
            READ_TYPE_SINGLE_DATA(mat, z, data, len);
            break;
#ifdef HAVE_MAT_INT64_T
        case MAT_T_INT64:
            READ_TYPE_INT64_DATA(mat, z, data, len);
            break;
#endif /* HAVE_MAT_UINT64_T */
#ifdef HAVE_MAT_UINT64_T
        case MAT_T_UINT64:
            READ_TYPE_UINT64_DATA(mat, z, data, len);
            break;
#endif /* HAVE_MAT_UINT64_T */
        case MAT_T_INT32:
            READ_TYPE_INT32_DATA(mat, z, data, len);
            break;
        case MAT_T_UINT32:
            READ_TYPE_UINT32_DATA(mat, z, data, len);
            break;
        case MAT_T_INT16:
            READ_TYPE_INT16_DATA(mat, z, data, len);
            break;
        case MAT_T_UINT16:
            READ_TYPE_UINT16_DATA(mat, z, data, len);
            break;
        case MAT_T_INT8:
            READ_TYPE_INT8_DATA(mat, z, data, len);
            break;
        case MAT_T_UINT8:
            READ_TYPE_UINT8_DATA(mat, z, data, len);
            break;
        default:
            break;
    }
    return len*Mat_SizeOf(data_type);
}

#undef READ_TYPE_DOUBLE_DATA
#undef READ_TYPE_SINGLE_DATA
#undef READ_TYPE_INT32_DATA
#undef READ_TYPE_UINT32_DATA
#undef READ_TYPE_INT16_DATA
#undef READ_TYPE_UINT16_DATA
#undef READ_TYPE_INT8_DATA
#undef READ_TYPE_UINT8_DATA
#ifdef HAVE_MAT_INT64_T
#undef READ_TYPE_INT64_DATA
#endif /* HAVE_MAT_INT64_T */
#ifdef HAVE_MAT_UINT64_T
#undef READ_TYPE_UINT64_DATA
#endif /* HAVE_MAT_UINT64_T */

#endif
