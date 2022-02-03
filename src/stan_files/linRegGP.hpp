/*
    MpiTemporalIso is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    MpiTemporalIso is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MpiTemporalIso.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.19.1

#include <stan/model/model_header.hpp>

namespace model_linRegGP_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_linRegGP");
    reader.add_event(47, 45, "end", "model_linRegGP");
    return reader;
}

#include <meta_header.hpp>
 class model_linRegGP : public prob_grad {
private:
        int N;
        int NT;
        vector_d y_mean;
        vector_d y_sigma;
        std::vector<double> t;
        matrix_d x;
public:
    model_linRegGP(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_linRegGP(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_linRegGP_namespace::model_linRegGP";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            // initialize data block variables from context__
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 1);

            current_statement_begin__ = 5;
            context__.validate_dims("data initialization", "NT", "int", context__.to_vec());
            NT = int(0);
            vals_i__ = context__.vals_i("NT");
            pos__ = 0;
            NT = vals_i__[pos__++];
            check_greater_or_equal(function__, "NT", NT, 1);

            current_statement_begin__ = 6;
            validate_non_negative_index("y_mean", "N", N);
            context__.validate_dims("data initialization", "y_mean", "vector_d", context__.to_vec(N));
            y_mean = Eigen::Matrix<double, Eigen::Dynamic, 1>(N);
            vals_r__ = context__.vals_r("y_mean");
            pos__ = 0;
            size_t y_mean_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < y_mean_j_1_max__; ++j_1__) {
                y_mean(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 7;
            validate_non_negative_index("y_sigma", "N", N);
            context__.validate_dims("data initialization", "y_sigma", "vector_d", context__.to_vec(N));
            y_sigma = Eigen::Matrix<double, Eigen::Dynamic, 1>(N);
            vals_r__ = context__.vals_r("y_sigma");
            pos__ = 0;
            size_t y_sigma_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < y_sigma_j_1_max__; ++j_1__) {
                y_sigma(j_1__) = vals_r__[pos__++];
            }

            current_statement_begin__ = 8;
            validate_non_negative_index("t", "NT", NT);
            context__.validate_dims("data initialization", "t", "double", context__.to_vec(NT));
            t = std::vector<double>(NT, double(0));
            vals_r__ = context__.vals_r("t");
            pos__ = 0;
            size_t t_k_0_max__ = NT;
            for (size_t k_0__ = 0; k_0__ < t_k_0_max__; ++k_0__) {
                t[k_0__] = vals_r__[pos__++];
            }

            current_statement_begin__ = 9;
            validate_non_negative_index("x", "N", N);
            validate_non_negative_index("x", "NT", NT);
            context__.validate_dims("data initialization", "x", "matrix_d", context__.to_vec(N,NT));
            x = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(N, NT);
            vals_r__ = context__.vals_r("x");
            pos__ = 0;
            size_t x_j_2_max__ = NT;
            size_t x_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < x_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < x_j_1_max__; ++j_1__) {
                    x(j_1__, j_2__) = vals_r__[pos__++];
                }
            }


            // initialize transformed data variables
            // execute transformed data statements

            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 22;
            num_params_r__ += 1;
            current_statement_begin__ = 23;
            num_params_r__ += 1;
            current_statement_begin__ = 24;
            num_params_r__ += 1;
            current_statement_begin__ = 25;
            validate_non_negative_index("interval", "NT", NT);
            num_params_r__ += NT;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_linRegGP() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        current_statement_begin__ = 22;
        if (!(context__.contains_r("mu")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "mu", "double", context__.to_vec());
        double mu(0);
        mu = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 23;
        if (!(context__.contains_r("alpha")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable alpha missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("alpha");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "alpha", "double", context__.to_vec());
        double alpha(0);
        alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, alpha);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable alpha: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 24;
        if (!(context__.contains_r("rho")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable rho missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("rho");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "rho", "double", context__.to_vec());
        double rho(0);
        rho = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, rho);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable rho: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 25;
        if (!(context__.contains_r("interval")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable interval missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("interval");
        pos__ = 0U;
        validate_non_negative_index("interval", "NT", NT);
        context__.validate_dims("parameter initialization", "interval", "vector_d", context__.to_vec(NT));
        Eigen::Matrix<double, Eigen::Dynamic, 1> interval(NT);
        size_t interval_j_1_max__ = NT;
        for (size_t j_1__ = 0; j_1__ < interval_j_1_max__; ++j_1__) {
            interval(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(interval);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable interval: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);

            // model parameters
            current_statement_begin__ = 22;
            local_scalar_t__ mu;
            (void) mu;  // dummy to suppress unused var warning
            if (jacobian__)
                mu = in__.scalar_constrain(lp__);
            else
                mu = in__.scalar_constrain();

            current_statement_begin__ = 23;
            local_scalar_t__ alpha;
            (void) alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha = in__.scalar_lb_constrain(0, lp__);
            else
                alpha = in__.scalar_lb_constrain(0);

            current_statement_begin__ = 24;
            local_scalar_t__ rho;
            (void) rho;  // dummy to suppress unused var warning
            if (jacobian__)
                rho = in__.scalar_lb_constrain(0, lp__);
            else
                rho = in__.scalar_lb_constrain(0);

            current_statement_begin__ = 25;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> interval;
            (void) interval;  // dummy to suppress unused var warning
            if (jacobian__)
                interval = in__.vector_constrain(NT, lp__);
            else
                interval = in__.vector_constrain(NT);

            // transformed parameters
            current_statement_begin__ = 28;
            validate_non_negative_index("muInt", "NT", NT);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> muInt(NT);
            stan::math::initialize(muInt, DUMMY_VAR__);
            stan::math::fill(muInt, DUMMY_VAR__);

            current_statement_begin__ = 29;
            validate_non_negative_index("sdInt", "NT", NT);
            validate_non_negative_index("sdInt", "NT", NT);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> sdInt(NT, NT);
            stan::math::initialize(sdInt, DUMMY_VAR__);
            stan::math::fill(sdInt, DUMMY_VAR__);

            current_statement_begin__ = 30;
            validate_non_negative_index("sdY", "N", N);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> sdY(N);
            stan::math::initialize(sdY, DUMMY_VAR__);
            stan::math::fill(sdY, DUMMY_VAR__);

            current_statement_begin__ = 31;
            validate_non_negative_index("meanY", "N", N);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> meanY(N);
            stan::math::initialize(meanY, DUMMY_VAR__);
            stan::math::fill(meanY, DUMMY_VAR__);

            // transformed parameters block statements
            current_statement_begin__ = 32;
            stan::math::assign(meanY, multiply(x, interval));
            current_statement_begin__ = 33;
            stan::math::assign(sdY, y_sigma);
            current_statement_begin__ = 34;
            stan::math::assign(muInt, rep_vector(mu, NT));
            current_statement_begin__ = 35;
            stan::math::assign(sdInt, cholesky_decompose(cov_exp_quad(t, alpha, rho)));

            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            current_statement_begin__ = 28;
            size_t muInt_j_1_max__ = NT;
            for (size_t j_1__ = 0; j_1__ < muInt_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(muInt(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: muInt" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable muInt: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 29;
            size_t sdInt_j_1_max__ = NT;
            size_t sdInt_j_2_max__ = NT;
            for (size_t j_1__ = 0; j_1__ < sdInt_j_1_max__; ++j_1__) {
                for (size_t j_2__ = 0; j_2__ < sdInt_j_2_max__; ++j_2__) {
                    if (stan::math::is_uninitialized(sdInt(j_1__, j_2__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: sdInt" << "(" << j_1__ << ", " << j_2__ << ")";
                        stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable sdInt: ") + msg__.str()), current_statement_begin__, prog_reader__());
                    }
                }
            }
            current_statement_begin__ = 30;
            size_t sdY_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < sdY_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(sdY(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: sdY" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable sdY: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 31;
            size_t meanY_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < meanY_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(meanY(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: meanY" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable meanY: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }

            // model body

            current_statement_begin__ = 39;
            lp_accum__.add(student_t_log<propto__>(mu, 3, 0, 20));
            current_statement_begin__ = 40;
            lp_accum__.add(normal_log<propto__>(rho, 1, 0.25));
            current_statement_begin__ = 41;
            lp_accum__.add(normal_log<propto__>(alpha, 2, 0.5));
            current_statement_begin__ = 42;
            lp_accum__.add(multi_normal_cholesky_log<propto__>(interval, muInt, sdInt));
            current_statement_begin__ = 44;
            lp_accum__.add(normal_log<propto__>(y_mean, meanY, sdY));

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("mu");
        names__.push_back("alpha");
        names__.push_back("rho");
        names__.push_back("interval");
        names__.push_back("muInt");
        names__.push_back("sdInt");
        names__.push_back("sdY");
        names__.push_back("meanY");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(NT);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(NT);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(NT);
        dims__.push_back(NT);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_linRegGP_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning

        // read-transform, write parameters
        double mu = in__.scalar_constrain();
        vars__.push_back(mu);

        double alpha = in__.scalar_lb_constrain(0);
        vars__.push_back(alpha);

        double rho = in__.scalar_lb_constrain(0);
        vars__.push_back(rho);

        Eigen::Matrix<double, Eigen::Dynamic, 1> interval = in__.vector_constrain(NT);
        size_t interval_j_1_max__ = NT;
        for (size_t j_1__ = 0; j_1__ < interval_j_1_max__; ++j_1__) {
            vars__.push_back(interval(j_1__));
        }

        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        if (!include_tparams__ && !include_gqs__) return;

        try {
            // declare and define transformed parameters
            current_statement_begin__ = 28;
            validate_non_negative_index("muInt", "NT", NT);
            Eigen::Matrix<double, Eigen::Dynamic, 1> muInt(NT);
            stan::math::initialize(muInt, DUMMY_VAR__);
            stan::math::fill(muInt, DUMMY_VAR__);

            current_statement_begin__ = 29;
            validate_non_negative_index("sdInt", "NT", NT);
            validate_non_negative_index("sdInt", "NT", NT);
            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> sdInt(NT, NT);
            stan::math::initialize(sdInt, DUMMY_VAR__);
            stan::math::fill(sdInt, DUMMY_VAR__);

            current_statement_begin__ = 30;
            validate_non_negative_index("sdY", "N", N);
            Eigen::Matrix<double, Eigen::Dynamic, 1> sdY(N);
            stan::math::initialize(sdY, DUMMY_VAR__);
            stan::math::fill(sdY, DUMMY_VAR__);

            current_statement_begin__ = 31;
            validate_non_negative_index("meanY", "N", N);
            Eigen::Matrix<double, Eigen::Dynamic, 1> meanY(N);
            stan::math::initialize(meanY, DUMMY_VAR__);
            stan::math::fill(meanY, DUMMY_VAR__);

            // do transformed parameters statements
            current_statement_begin__ = 32;
            stan::math::assign(meanY, multiply(x, interval));
            current_statement_begin__ = 33;
            stan::math::assign(sdY, y_sigma);
            current_statement_begin__ = 34;
            stan::math::assign(muInt, rep_vector(mu, NT));
            current_statement_begin__ = 35;
            stan::math::assign(sdInt, cholesky_decompose(cov_exp_quad(t, alpha, rho)));

            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // write transformed parameters
            if (include_tparams__) {
                size_t muInt_j_1_max__ = NT;
                for (size_t j_1__ = 0; j_1__ < muInt_j_1_max__; ++j_1__) {
                    vars__.push_back(muInt(j_1__));
                }
                size_t sdInt_j_2_max__ = NT;
                size_t sdInt_j_1_max__ = NT;
                for (size_t j_2__ = 0; j_2__ < sdInt_j_2_max__; ++j_2__) {
                    for (size_t j_1__ = 0; j_1__ < sdInt_j_1_max__; ++j_1__) {
                        vars__.push_back(sdInt(j_1__, j_2__));
                    }
                }
                size_t sdY_j_1_max__ = N;
                for (size_t j_1__ = 0; j_1__ < sdY_j_1_max__; ++j_1__) {
                    vars__.push_back(sdY(j_1__));
                }
                size_t meanY_j_1_max__ = N;
                for (size_t j_1__ = 0; j_1__ < meanY_j_1_max__; ++j_1__) {
                    vars__.push_back(meanY(j_1__));
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_linRegGP";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "rho";
        param_names__.push_back(param_name_stream__.str());
        size_t interval_j_1_max__ = NT;
        for (size_t j_1__ = 0; j_1__ < interval_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "interval" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            size_t muInt_j_1_max__ = NT;
            for (size_t j_1__ = 0; j_1__ < muInt_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "muInt" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t sdInt_j_2_max__ = NT;
            size_t sdInt_j_1_max__ = NT;
            for (size_t j_2__ = 0; j_2__ < sdInt_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < sdInt_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "sdInt" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
            size_t sdY_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < sdY_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "sdY" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t meanY_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < meanY_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "meanY" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "rho";
        param_names__.push_back(param_name_stream__.str());
        size_t interval_j_1_max__ = NT;
        for (size_t j_1__ = 0; j_1__ < interval_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "interval" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            size_t muInt_j_1_max__ = NT;
            for (size_t j_1__ = 0; j_1__ < muInt_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "muInt" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t sdInt_j_2_max__ = NT;
            size_t sdInt_j_1_max__ = NT;
            for (size_t j_2__ = 0; j_2__ < sdInt_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < sdInt_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "sdInt" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
            size_t sdY_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < sdY_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "sdY" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t meanY_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < meanY_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "meanY" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__) return;
    }

}; // model

}  // namespace

typedef model_linRegGP_namespace::model_linRegGP stan_model;


#endif
