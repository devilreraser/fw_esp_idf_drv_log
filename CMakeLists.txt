idf_build_get_property(project_dir PROJECT_DIR)

# Initialize an empty list to hold conditional requirements
set(conditionally_required_components "")

if(EXISTS "${project_dir}/components/drv_console")
    list(APPEND conditionally_required_components "drv_console")
endif()

idf_component_register(SRCS "cmd_log.c" "drv_log.c" 
                    INCLUDE_DIRS "." 
                    REQUIRES 
                        "console" 
                        ${conditionally_required_components} 
                        "log"
                                      )
                 

