/*
 * This file is part of the Colobot: Gold Edition source code
 * Copyright (C) 2001-2020, Daniel Roux, EPSITEC SA & TerranovaTeam
 * http://epsitec.ch; http://colobot.info; http://github.com/colobot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://gnu.org/licenses
 */

#pragma once

#include "CBot/CBotInstr/CBotInstr.h"

namespace CBot
{

/**
 * \brief The "repeat" loop - repeat (times) { ... }
 */
class CBotRepeat : public CBotInstr
{
public:
    CBotRepeat();
    ~CBotRepeat();

    /// Static method used for compilation
    static CBotInstr* Compile(CBotToken* &p, CBotCStack* pStack);

    /// Execute
    bool Execute(CBotStack* &pj) override;

    /// Restore state
    void RestoreState(CBotStack* &pj, bool bMain) override;

protected:
    virtual const std::string GetDebugName() override { return "CBotRepeat"; }
    virtual std::string GetDebugData() override;
    virtual std::map<std::string, CBotInstr*> GetDebugLinks() override;

private:
    /// Number of iterations
    CBotInstr*    m_expr;

    /// Instructions
    CBotInstr*    m_block;

    /// Label
    std::string   m_label;            // a label if there is

};

} // namespace CBot
