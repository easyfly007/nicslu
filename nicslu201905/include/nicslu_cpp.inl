//a simple C++ wrapper of NICSLU
//version 201905
#ifndef __NICSLU_CPP__
#define __NICSLU_CPP__

#ifndef __cplusplus
#error MUST USE C++!
#endif

#include "nicslu.h"

class CNicsLU
{
public:
	inline CNicsLU()
	{
		ctx = NULL;
		ctrl = NULL;
		info = NULL;
		last_err = NULL;
	}
	inline ~CNicsLU()
	{
		if (ctx != NULL)
		{
			NicsLU_Free(ctx);
		}
	}
	inline void SetConfiguration(int id, _double_t value)
	{
		ctrl[id] = value;
	}
	inline _double_t GetInformation(int id)
	{
		return info[id];
	}
	inline const char *GetLastErrorMsg()
	{
		return last_err;
	}
	//@1
	inline int Initialize()
	{
		return NicsLU_Initialize(&ctx, &ctrl, &info, &last_err);
	}
	//@2
	inline int Free()
	{
		ctrl = NULL;
		info = NULL;
		last_err = NULL;
		if (ctx != NULL)
		{
			NicsLU_Free(ctx);
			ctx = NULL;
		}
		return __OK;
	}
	//@3
	inline int Analyze(_uint_t n, const _double_t *ax, const _uint_t *ai, const _uint_t *ap,
		_matrix_type_t mtype, _uint_t *rp_user = NULL, _uint_t *cp_user = NULL, _double_t
		*row_scale = NULL, _double_t *col_scale = NULL)
	{
		return NicsLU_Analyze(ctx, n, ax, ai, ap, mtype, rp_user, cp_user, row_scale, col_scale);
	}
	//@4
	inline int CreateThreads(int threads = 0)
	{
		return NicsLU_CreateThreads(ctx, threads);
	}
	//@5
	inline int DestroyThreads()
	{
		return NicsLU_DestroyThreads(ctx);
	}
	//@6
	inline int SetThreadSchedule(_thread_sched_t op, int param)
	{
		return NicsLU_SetThreadSchedule(ctx, op, param);
	}
	//@7
	inline int Factorize(const _double_t *ax, int threads = 0)
	{
		return NicsLU_Factorize(ctx, ax, threads);
	}
	//@8
	inline int ReFactorize(const _double_t *ax, int threads = 0)
	{
		return NicsLU_ReFactorize(ctx, ax, threads);
	}
	//@9
	inline int Solve(_double_t *b, _double_t *x)
	{
		return NicsLU_Solve(ctx, b, x);
	}
	//@10
	inline int Refine(const _double_t *ax, const _double_t *b, _double_t *x)
	{
		return NicsLU_Refine(ctx, ax, b, x);
	}
	//@11
	inline int Flops(int threads, _double_t *fflops, _double_t *sflops)
	{
		return NicsLU_Flops(ctx, threads, fflops, sflops);
	}
	//@12
	inline int MemoryTraffic(_double_t *fcomm, _double_t *scomm)
	{
		return NicsLU_MemoryTraffic(ctx, fcomm, scomm);
	}
	//@13
	inline int GetFactors(_double_t *lx, _uint_t *li, _size_t *lp, _double_t *ux, _uint_t *ui, _size_t *up,
		bool sort, _uint_t *row_perm, _uint_t *col_perm, _double_t *row_scale, _double_t *col_scale)
	{
		return NicsLU_GetFactors(ctx, lx, li, lp, ux, ui, up, sort, row_perm, col_perm, row_scale, col_scale);
	}
	//@14
	inline int ConditionNumber(const _double_t *ax, _double_t *cond)
	{
		return NicsLU_ConditionNumber(ctx, ax, cond);
	}
	//@15
	inline int MemoryUsage(_size_t *memuse)
	{
		return NicsLU_MemoryUsage(ctx, memuse);
	}
	//@16
	inline int Determinant(_double_t *det_coef, _double_t *det_exp)
	{
		return NicsLU_Determinant(ctx, det_coef, det_exp);
	}
	//@17
	inline int FactorizeMatrix(const _double_t *ax, int threads = 0)
	{
		return NicsLU_FactorizeMatrix(ctx, ax, threads);
	}
	//@18
	inline int SolveAndRefine(const _double_t *ax, const _double_t *b, _double_t *x)
	{
		return NicsLU_SolveAndRefine(ctx, ax, b, x);
	}
	//@19
	inline int Performance(int tsync, int threads, _double_t *perf)
	{
		return NicsLU_Performance(ctx, tsync, threads, perf);
	}
	//@20
	static inline int SparseResidual(_uint_t n, const _double_t *ax, const _uint_t *ai, const _uint_t *ap,
		const _double_t *b, const _double_t *x, _double_t *res, _matrix_type_t mtype)
	{
		return ::SparseResidual(n, ax, ai, ap, b, x, res, mtype);
	}
	//@21
	static inline int SparseTranspose(_uint_t n, _double_t *ax, _uint_t *ai, _uint_t *ap, _transpose_t op)
	{
		return ::SparseTranspose(n, ax, ai, ap, op);
	}
	//@22
	static inline int ReadMatrixMarket(const char *file, _uint_t *row, _uint_t *col, _uint_t *nnz, _double_t *ax,
		_uint_t *ai, _uint_t *ap, int iscomplex)
	{
		return ::ReadMatrixMarket(file, row, col, nnz, ax, ai, ap, iscomplex);
	}
	//@23
	static inline int SparseHalfToSymmetricFull(_uint_t n, const _double_t *ax, const _uint_t *ai, 
		const _uint_t *ap, _double_t *aax, _uint_t *aai, _uint_t *aap, int iscomplex)
	{
		return ::SparseHalfToSymmetricFull(n, ax, ai, ap, aax, aai, aap, iscomplex);
	}
	//@24
	static inline int PrintNicsLULicense(void (*fptr)(const char *))
	{
		return ::PrintNicsLULicense(fptr);
	}

private:
	_handle_t ctx;

public:
	_double_t *ctrl;
	const _double_t *info;
	const char *last_err;
};

#endif
